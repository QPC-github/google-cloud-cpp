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
// source: google/api/apikeys/v2/apikeys.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_APIKEYS_INTERNAL_API_KEYS_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_APIKEYS_INTERNAL_API_KEYS_CONNECTION_IMPL_H

#include "google/cloud/apikeys/api_keys_connection.h"
#include "google/cloud/apikeys/api_keys_connection_idempotency_policy.h"
#include "google/cloud/apikeys/api_keys_options.h"
#include "google/cloud/apikeys/internal/api_keys_retry_traits.h"
#include "google/cloud/apikeys/internal/api_keys_stub.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace apikeys_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ApiKeysConnectionImpl : public apikeys::ApiKeysConnection {
 public:
  ~ApiKeysConnectionImpl() override = default;

  ApiKeysConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<apikeys_internal::ApiKeysStub> stub, Options options);

  Options options() override { return options_; }

  future<StatusOr<google::api::apikeys::v2::Key>> CreateKey(
      google::api::apikeys::v2::CreateKeyRequest const& request) override;

  StreamRange<google::api::apikeys::v2::Key> ListKeys(
      google::api::apikeys::v2::ListKeysRequest request) override;

  StatusOr<google::api::apikeys::v2::Key> GetKey(
      google::api::apikeys::v2::GetKeyRequest const& request) override;

  StatusOr<google::api::apikeys::v2::GetKeyStringResponse> GetKeyString(
      google::api::apikeys::v2::GetKeyStringRequest const& request) override;

  future<StatusOr<google::api::apikeys::v2::Key>> UpdateKey(
      google::api::apikeys::v2::UpdateKeyRequest const& request) override;

  future<StatusOr<google::api::apikeys::v2::Key>> DeleteKey(
      google::api::apikeys::v2::DeleteKeyRequest const& request) override;

  future<StatusOr<google::api::apikeys::v2::Key>> UndeleteKey(
      google::api::apikeys::v2::UndeleteKeyRequest const& request) override;

  StatusOr<google::api::apikeys::v2::LookupKeyResponse> LookupKey(
      google::api::apikeys::v2::LookupKeyRequest const& request) override;

 private:
  std::unique_ptr<apikeys::ApiKeysRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<apikeys::ApiKeysRetryPolicyOption>()) {
      return options.get<apikeys::ApiKeysRetryPolicyOption>()->clone();
    }
    return options_.get<apikeys::ApiKeysRetryPolicyOption>()->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<apikeys::ApiKeysBackoffPolicyOption>()) {
      return options.get<apikeys::ApiKeysBackoffPolicyOption>()->clone();
    }
    return options_.get<apikeys::ApiKeysBackoffPolicyOption>()->clone();
  }

  std::unique_ptr<apikeys::ApiKeysConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<apikeys::ApiKeysConnectionIdempotencyPolicyOption>()) {
      return options.get<apikeys::ApiKeysConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return options_.get<apikeys::ApiKeysConnectionIdempotencyPolicyOption>()
        ->clone();
  }

  std::unique_ptr<PollingPolicy> polling_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<apikeys::ApiKeysPollingPolicyOption>()) {
      return options.get<apikeys::ApiKeysPollingPolicyOption>()->clone();
    }
    return options_.get<apikeys::ApiKeysPollingPolicyOption>()->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<apikeys_internal::ApiKeysStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace apikeys_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_APIKEYS_INTERNAL_API_KEYS_CONNECTION_IMPL_H