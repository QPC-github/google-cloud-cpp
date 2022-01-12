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
// source: google/cloud/clouddms/v1/clouddms.proto

#include "google/cloud/datamigration/data_migration_client.h"
#include "google/cloud/datamigration/internal/data_migration_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace datamigration {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DataMigrationServiceClient::DataMigrationServiceClient(
    std::shared_ptr<DataMigrationServiceConnection> connection, Options options)
    : connection_(std::move(connection)),
      options_(datamigration_internal::DataMigrationServiceDefaultOptions(
          std::move(options))) {}
DataMigrationServiceClient::~DataMigrationServiceClient() = default;

StreamRange<google::cloud::clouddms::v1::MigrationJob>
DataMigrationServiceClient::ListMigrationJobs(std::string const& parent,
                                              Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::clouddms::v1::ListMigrationJobsRequest request;
  request.set_parent(parent);
  return connection_->ListMigrationJobs(request);
}

StreamRange<google::cloud::clouddms::v1::MigrationJob>
DataMigrationServiceClient::ListMigrationJobs(
    google::cloud::clouddms::v1::ListMigrationJobsRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListMigrationJobs(std::move(request));
}

StatusOr<google::cloud::clouddms::v1::MigrationJob>
DataMigrationServiceClient::GetMigrationJob(std::string const& name,
                                            Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::clouddms::v1::GetMigrationJobRequest request;
  request.set_name(name);
  return connection_->GetMigrationJob(request);
}

StatusOr<google::cloud::clouddms::v1::MigrationJob>
DataMigrationServiceClient::GetMigrationJob(
    google::cloud::clouddms::v1::GetMigrationJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceClient::CreateMigrationJob(
    std::string const& parent,
    google::cloud::clouddms::v1::MigrationJob const& migration_job,
    std::string const& migration_job_id, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::clouddms::v1::CreateMigrationJobRequest request;
  request.set_parent(parent);
  *request.mutable_migration_job() = migration_job;
  request.set_migration_job_id(migration_job_id);
  return connection_->CreateMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceClient::CreateMigrationJob(
    google::cloud::clouddms::v1::CreateMigrationJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceClient::UpdateMigrationJob(
    google::cloud::clouddms::v1::MigrationJob const& migration_job,
    google::protobuf::FieldMask const& update_mask, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::clouddms::v1::UpdateMigrationJobRequest request;
  *request.mutable_migration_job() = migration_job;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceClient::UpdateMigrationJob(
    google::cloud::clouddms::v1::UpdateMigrationJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::OperationMetadata>>
DataMigrationServiceClient::DeleteMigrationJob(std::string const& name,
                                               Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::clouddms::v1::DeleteMigrationJobRequest request;
  request.set_name(name);
  return connection_->DeleteMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::OperationMetadata>>
DataMigrationServiceClient::DeleteMigrationJob(
    google::cloud::clouddms::v1::DeleteMigrationJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DeleteMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceClient::StartMigrationJob(
    google::cloud::clouddms::v1::StartMigrationJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->StartMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceClient::StopMigrationJob(
    google::cloud::clouddms::v1::StopMigrationJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->StopMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceClient::ResumeMigrationJob(
    google::cloud::clouddms::v1::ResumeMigrationJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ResumeMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceClient::PromoteMigrationJob(
    google::cloud::clouddms::v1::PromoteMigrationJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->PromoteMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceClient::VerifyMigrationJob(
    google::cloud::clouddms::v1::VerifyMigrationJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->VerifyMigrationJob(request);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceClient::RestartMigrationJob(
    google::cloud::clouddms::v1::RestartMigrationJobRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->RestartMigrationJob(request);
}

StatusOr<google::cloud::clouddms::v1::SshScript>
DataMigrationServiceClient::GenerateSshScript(
    google::cloud::clouddms::v1::GenerateSshScriptRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GenerateSshScript(request);
}

StreamRange<google::cloud::clouddms::v1::ConnectionProfile>
DataMigrationServiceClient::ListConnectionProfiles(std::string const& parent,
                                                   Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::clouddms::v1::ListConnectionProfilesRequest request;
  request.set_parent(parent);
  return connection_->ListConnectionProfiles(request);
}

StreamRange<google::cloud::clouddms::v1::ConnectionProfile>
DataMigrationServiceClient::ListConnectionProfiles(
    google::cloud::clouddms::v1::ListConnectionProfilesRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListConnectionProfiles(std::move(request));
}

StatusOr<google::cloud::clouddms::v1::ConnectionProfile>
DataMigrationServiceClient::GetConnectionProfile(std::string const& name,
                                                 Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::clouddms::v1::GetConnectionProfileRequest request;
  request.set_name(name);
  return connection_->GetConnectionProfile(request);
}

StatusOr<google::cloud::clouddms::v1::ConnectionProfile>
DataMigrationServiceClient::GetConnectionProfile(
    google::cloud::clouddms::v1::GetConnectionProfileRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetConnectionProfile(request);
}

future<StatusOr<google::cloud::clouddms::v1::ConnectionProfile>>
DataMigrationServiceClient::CreateConnectionProfile(
    std::string const& parent,
    google::cloud::clouddms::v1::ConnectionProfile const& connection_profile,
    std::string const& connection_profile_id, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::clouddms::v1::CreateConnectionProfileRequest request;
  request.set_parent(parent);
  *request.mutable_connection_profile() = connection_profile;
  request.set_connection_profile_id(connection_profile_id);
  return connection_->CreateConnectionProfile(request);
}

future<StatusOr<google::cloud::clouddms::v1::ConnectionProfile>>
DataMigrationServiceClient::CreateConnectionProfile(
    google::cloud::clouddms::v1::CreateConnectionProfileRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateConnectionProfile(request);
}

future<StatusOr<google::cloud::clouddms::v1::ConnectionProfile>>
DataMigrationServiceClient::UpdateConnectionProfile(
    google::cloud::clouddms::v1::ConnectionProfile const& connection_profile,
    google::protobuf::FieldMask const& update_mask, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::clouddms::v1::UpdateConnectionProfileRequest request;
  *request.mutable_connection_profile() = connection_profile;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateConnectionProfile(request);
}

future<StatusOr<google::cloud::clouddms::v1::ConnectionProfile>>
DataMigrationServiceClient::UpdateConnectionProfile(
    google::cloud::clouddms::v1::UpdateConnectionProfileRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateConnectionProfile(request);
}

future<StatusOr<google::cloud::clouddms::v1::OperationMetadata>>
DataMigrationServiceClient::DeleteConnectionProfile(std::string const& name,
                                                    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::cloud::clouddms::v1::DeleteConnectionProfileRequest request;
  request.set_name(name);
  return connection_->DeleteConnectionProfile(request);
}

future<StatusOr<google::cloud::clouddms::v1::OperationMetadata>>
DataMigrationServiceClient::DeleteConnectionProfile(
    google::cloud::clouddms::v1::DeleteConnectionProfileRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DeleteConnectionProfile(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datamigration
}  // namespace cloud
}  // namespace google