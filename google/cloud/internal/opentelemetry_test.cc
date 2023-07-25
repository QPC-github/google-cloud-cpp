// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/opentelemetry_options.h"
#include <gmock/gmock.h>
#include <opentelemetry/trace/default_span.h>
#include <opentelemetry/version.h>

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {
namespace {

using ::testing::IsEmpty;
using ::testing::Not;

TEST(OpenTelemetry, IsUsable) {
  auto version = std::string{OPENTELEMETRY_VERSION};
  EXPECT_THAT(version, Not(IsEmpty()));
  auto span = opentelemetry::trace::DefaultSpan::GetInvalid();
  EXPECT_EQ(span.ToString(), "DefaultSpan");
}

TEST(OpenTelemetry, TracingEnabled) {
  auto options = Options{};
  EXPECT_FALSE(TracingEnabled(options));

  options.set<OpenTelemetryTracingOption>(false);
  EXPECT_FALSE(TracingEnabled(options));

  options.set<OpenTelemetryTracingOption>(true);
  EXPECT_TRUE(TracingEnabled(options));
}

}  // namespace
}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY