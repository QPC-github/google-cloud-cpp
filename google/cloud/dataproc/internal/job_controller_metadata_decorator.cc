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
// source: google/cloud/dataproc/v1/jobs.proto

#include "google/cloud/dataproc/internal/job_controller_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dataproc/v1/jobs.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dataproc_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

JobControllerMetadata::JobControllerMetadata(
    std::shared_ptr<JobControllerStub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::cloud::dataproc::v1::Job> JobControllerMetadata::SubmitJob(
    grpc::ClientContext& context,
    google::cloud::dataproc::v1::SubmitJobRequest const& request) {
  SetMetadata(context, {});
  return child_->SubmitJob(context, request);
}

future<StatusOr<google::longrunning::Operation>>
JobControllerMetadata::AsyncSubmitJobAsOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::dataproc::v1::SubmitJobRequest const& request) {
  SetMetadata(*context, {});
  return child_->AsyncSubmitJobAsOperation(cq, std::move(context), request);
}

StatusOr<google::cloud::dataproc::v1::Job> JobControllerMetadata::GetJob(
    grpc::ClientContext& context,
    google::cloud::dataproc::v1::GetJobRequest const& request) {
  SetMetadata(context, {});
  return child_->GetJob(context, request);
}

StatusOr<google::cloud::dataproc::v1::ListJobsResponse>
JobControllerMetadata::ListJobs(
    grpc::ClientContext& context,
    google::cloud::dataproc::v1::ListJobsRequest const& request) {
  SetMetadata(context, {});
  return child_->ListJobs(context, request);
}

StatusOr<google::cloud::dataproc::v1::Job> JobControllerMetadata::UpdateJob(
    grpc::ClientContext& context,
    google::cloud::dataproc::v1::UpdateJobRequest const& request) {
  SetMetadata(context, {});
  return child_->UpdateJob(context, request);
}

StatusOr<google::cloud::dataproc::v1::Job> JobControllerMetadata::CancelJob(
    grpc::ClientContext& context,
    google::cloud::dataproc::v1::CancelJobRequest const& request) {
  SetMetadata(context, {});
  return child_->CancelJob(context, request);
}

Status JobControllerMetadata::DeleteJob(
    grpc::ClientContext& context,
    google::cloud::dataproc::v1::DeleteJobRequest const& request) {
  SetMetadata(context, {});
  return child_->DeleteJob(context, request);
}

future<StatusOr<google::longrunning::Operation>>
JobControllerMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> JobControllerMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void JobControllerMetadata::SetMetadata(grpc::ClientContext& context,
                                        std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void JobControllerMetadata::SetMetadata(grpc::ClientContext& context) {
  context.AddMetadata("x-goog-api-client", api_client_header_);
  auto const& options = internal::CurrentOptions();
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  if (options.has<AuthorityOption>()) {
    context.set_authority(options.get<AuthorityOption>());
  }
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataproc_internal
}  // namespace cloud
}  // namespace google