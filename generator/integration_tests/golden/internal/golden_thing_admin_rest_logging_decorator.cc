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
// source: generator/integration_tests/test.proto

#include "generator/integration_tests/golden/internal/golden_thing_admin_rest_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <memory>

namespace google {
namespace cloud {
namespace golden_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

GoldenThingAdminRestLogging::GoldenThingAdminRestLogging(
    std::shared_ptr<GoldenThingAdminRestStub> child,
    TracingOptions tracing_options,
    std::set<std::string> components)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::test::admin::database::v1::ListDatabasesResponse>
GoldenThingAdminRestLogging::ListDatabases(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::ListDatabasesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::ListDatabasesRequest const& request) {
        return child_->ListDatabases(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::longrunning::Operation>
GoldenThingAdminRestLogging::CreateDatabase(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::CreateDatabaseRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::CreateDatabaseRequest const& request) {
        return child_->CreateDatabase(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::Database>
GoldenThingAdminRestLogging::GetDatabase(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::GetDatabaseRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::GetDatabaseRequest const& request) {
        return child_->GetDatabase(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::longrunning::Operation>
GoldenThingAdminRestLogging::UpdateDatabaseDdl(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::UpdateDatabaseDdlRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::UpdateDatabaseDdlRequest const& request) {
        return child_->UpdateDatabaseDdl(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

Status
GoldenThingAdminRestLogging::DropDatabase(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::DropDatabaseRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::DropDatabaseRequest const& request) {
        return child_->DropDatabase(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::GetDatabaseDdlResponse>
GoldenThingAdminRestLogging::GetDatabaseDdl(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::GetDatabaseDdlRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::GetDatabaseDdlRequest const& request) {
        return child_->GetDatabaseDdl(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::iam::v1::Policy>
GoldenThingAdminRestLogging::SetIamPolicy(
    rest_internal::RestContext& rest_context,
    google::iam::v1::SetIamPolicyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::iam::v1::SetIamPolicyRequest const& request) {
        return child_->SetIamPolicy(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::iam::v1::Policy>
GoldenThingAdminRestLogging::GetIamPolicy(
    rest_internal::RestContext& rest_context,
    google::iam::v1::GetIamPolicyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::iam::v1::GetIamPolicyRequest const& request) {
        return child_->GetIamPolicy(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
GoldenThingAdminRestLogging::TestIamPermissions(
    rest_internal::RestContext& rest_context,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::iam::v1::TestIamPermissionsRequest const& request) {
        return child_->TestIamPermissions(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::longrunning::Operation>
GoldenThingAdminRestLogging::CreateBackup(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::CreateBackupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::CreateBackupRequest const& request) {
        return child_->CreateBackup(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::Backup>
GoldenThingAdminRestLogging::GetBackup(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::GetBackupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::GetBackupRequest const& request) {
        return child_->GetBackup(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::Backup>
GoldenThingAdminRestLogging::UpdateBackup(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::UpdateBackupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::UpdateBackupRequest const& request) {
        return child_->UpdateBackup(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

Status
GoldenThingAdminRestLogging::DeleteBackup(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::DeleteBackupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::DeleteBackupRequest const& request) {
        return child_->DeleteBackup(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::ListBackupsResponse>
GoldenThingAdminRestLogging::ListBackups(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::ListBackupsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::ListBackupsRequest const& request) {
        return child_->ListBackups(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::longrunning::Operation>
GoldenThingAdminRestLogging::RestoreDatabase(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::RestoreDatabaseRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::RestoreDatabaseRequest const& request) {
        return child_->RestoreDatabase(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::ListDatabaseOperationsResponse>
GoldenThingAdminRestLogging::ListDatabaseOperations(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::ListDatabaseOperationsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::ListDatabaseOperationsRequest const& request) {
        return child_->ListDatabaseOperations(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::ListBackupOperationsResponse>
GoldenThingAdminRestLogging::ListBackupOperations(
    rest_internal::RestContext& rest_context,
    google::test::admin::database::v1::ListBackupOperationsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::test::admin::database::v1::ListBackupOperationsRequest const& request) {
        return child_->ListBackupOperations(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace golden_internal
}  // namespace cloud
}  // namespace google