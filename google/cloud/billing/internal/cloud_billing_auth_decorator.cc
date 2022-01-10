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
// source: google/cloud/billing/v1/cloud_billing.proto

#include "google/cloud/billing/internal/cloud_billing_auth_decorator.h"
#include <google/cloud/billing/v1/cloud_billing.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace billing_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudBillingAuth::CloudBillingAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<CloudBillingStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingAuth::GetBillingAccount(
    grpc::ClientContext& context,
    google::cloud::billing::v1::GetBillingAccountRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetBillingAccount(context, request);
}

StatusOr<google::cloud::billing::v1::ListBillingAccountsResponse>
CloudBillingAuth::ListBillingAccounts(
    grpc::ClientContext& context,
    google::cloud::billing::v1::ListBillingAccountsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListBillingAccounts(context, request);
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingAuth::UpdateBillingAccount(
    grpc::ClientContext& context,
    google::cloud::billing::v1::UpdateBillingAccountRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateBillingAccount(context, request);
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingAuth::CreateBillingAccount(
    grpc::ClientContext& context,
    google::cloud::billing::v1::CreateBillingAccountRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateBillingAccount(context, request);
}

StatusOr<google::cloud::billing::v1::ListProjectBillingInfoResponse>
CloudBillingAuth::ListProjectBillingInfo(
    grpc::ClientContext& context,
    google::cloud::billing::v1::ListProjectBillingInfoRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListProjectBillingInfo(context, request);
}

StatusOr<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingAuth::GetProjectBillingInfo(
    grpc::ClientContext& context,
    google::cloud::billing::v1::GetProjectBillingInfoRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetProjectBillingInfo(context, request);
}

StatusOr<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingAuth::UpdateProjectBillingInfo(
    grpc::ClientContext& context,
    google::cloud::billing::v1::UpdateProjectBillingInfoRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateProjectBillingInfo(context, request);
}

StatusOr<google::iam::v1::Policy> CloudBillingAuth::GetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::GetIamPolicyRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetIamPolicy(context, request);
}

StatusOr<google::iam::v1::Policy> CloudBillingAuth::SetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::SetIamPolicyRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->SetIamPolicy(context, request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
CloudBillingAuth::TestIamPermissions(
    grpc::ClientContext& context,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->TestIamPermissions(context, request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace billing_internal
}  // namespace cloud
}  // namespace google