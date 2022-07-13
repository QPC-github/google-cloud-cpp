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
// source: google/cloud/run/v2/service.proto

#include "google/cloud/run/services_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace run {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

ServicesConnectionIdempotencyPolicy::~ServicesConnectionIdempotencyPolicy() =
    default;

namespace {
class DefaultServicesConnectionIdempotencyPolicy
    : public ServicesConnectionIdempotencyPolicy {
 public:
  ~DefaultServicesConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<ServicesConnectionIdempotencyPolicy> clone() const override {
    return absl::make_unique<DefaultServicesConnectionIdempotencyPolicy>(*this);
  }

  Idempotency CreateService(
      google::cloud::run::v2::CreateServiceRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency GetService(
      google::cloud::run::v2::GetServiceRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency ListServices(
      google::cloud::run::v2::ListServicesRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency UpdateService(
      google::cloud::run::v2::UpdateServiceRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteService(
      google::cloud::run::v2::DeleteServiceRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const& request) override {
    return request.policy().etag().empty() ? Idempotency::kNonIdempotent
                                           : Idempotency::kIdempotent;
  }

  Idempotency TestIamPermissions(
      google::iam::v1::TestIamPermissionsRequest const&) override {
    return Idempotency::kNonIdempotent;
  }
};
}  // namespace

std::unique_ptr<ServicesConnectionIdempotencyPolicy>
MakeDefaultServicesConnectionIdempotencyPolicy() {
  return absl::make_unique<DefaultServicesConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace run
}  // namespace cloud
}  // namespace google