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
// source: google/cloud/dataplex/v1/content.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_CONTENT_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_CONTENT_CONNECTION_H

#include "google/cloud/dataplex/content_connection_idempotency_policy.h"
#include "google/cloud/dataplex/internal/content_retry_traits.h"
#include "google/cloud/dataplex/internal/content_stub.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace dataplex {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ContentServiceRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        dataplex_internal::ContentServiceRetryTraits>;

using ContentServiceLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        dataplex_internal::ContentServiceRetryTraits>;

using ContentServiceLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        dataplex_internal::ContentServiceRetryTraits>;

class ContentServiceConnection {
 public:
  virtual ~ContentServiceConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StatusOr<google::cloud::dataplex::v1::Content> CreateContent(
      google::cloud::dataplex::v1::CreateContentRequest const& request);

  virtual StatusOr<google::cloud::dataplex::v1::Content> UpdateContent(
      google::cloud::dataplex::v1::UpdateContentRequest const& request);

  virtual Status DeleteContent(
      google::cloud::dataplex::v1::DeleteContentRequest const& request);

  virtual StatusOr<google::cloud::dataplex::v1::Content> GetContent(
      google::cloud::dataplex::v1::GetContentRequest const& request);

  virtual StreamRange<google::cloud::dataplex::v1::Content> ListContent(
      google::cloud::dataplex::v1::ListContentRequest request);
};

std::shared_ptr<ContentServiceConnection> MakeContentServiceConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataplex
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace dataplex_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<dataplex::ContentServiceConnection>
MakeContentServiceConnection(std::shared_ptr<ContentServiceStub> stub,
                             Options options);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataplex_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_CONTENT_CONNECTION_H