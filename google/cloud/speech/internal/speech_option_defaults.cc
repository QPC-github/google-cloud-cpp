// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/speech/v1/cloud_speech.proto

#include "google/cloud/speech/internal/speech_option_defaults.h"
#include "google/cloud/speech/speech_connection.h"
#include "google/cloud/speech/speech_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace speech_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options SpeechDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_SPEECH_ENDPOINT", "",
      "speech.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<speech::SpeechRetryPolicyOption>()) {
    options.set<speech::SpeechRetryPolicyOption>(
        speech::SpeechLimitedTimeRetryPolicy(std::chrono::minutes(30)).clone());
  }
  if (!options.has<speech::SpeechBackoffPolicyOption>()) {
    options.set<speech::SpeechBackoffPolicyOption>(
        ExponentialBackoffPolicy(std::chrono::seconds(1),
                                 std::chrono::minutes(5), kBackoffScaling)
            .clone());
  }
  if (!options.has<speech::SpeechPollingPolicyOption>()) {
    options.set<speech::SpeechPollingPolicyOption>(
        GenericPollingPolicy<speech::SpeechRetryPolicyOption::Type,
                             speech::SpeechBackoffPolicyOption::Type>(
            options.get<speech::SpeechRetryPolicyOption>()->clone(),
            options.get<speech::SpeechBackoffPolicyOption>()->clone())
            .clone());
  }
  if (!options.has<speech::SpeechConnectionIdempotencyPolicyOption>()) {
    options.set<speech::SpeechConnectionIdempotencyPolicyOption>(
        speech::MakeDefaultSpeechConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace speech_internal
}  // namespace cloud
}  // namespace google