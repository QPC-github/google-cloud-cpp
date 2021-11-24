// Copyright 2021 Google LLC
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
// source: google/bigtable/admin/v2/bigtable_table_admin.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGTABLE_ADMIN_BIGTABLE_TABLE_ADMIN_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGTABLE_ADMIN_BIGTABLE_TABLE_ADMIN_CLIENT_H

#include "google/cloud/bigtable/admin/bigtable_table_admin_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/iam_updater.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>

namespace google {
namespace cloud {
namespace bigtable_admin {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service for creating, configuring, and deleting Cloud Bigtable tables.
///
///
/// Provides access to the table schemas only, not the data stored within
/// the tables.
///
class BigtableTableAdminClient {
 public:
  explicit BigtableTableAdminClient(
      std::shared_ptr<BigtableTableAdminConnection> connection);
  ~BigtableTableAdminClient();

  //@{
  // @name Copy and move support
  BigtableTableAdminClient(BigtableTableAdminClient const&) = default;
  BigtableTableAdminClient& operator=(BigtableTableAdminClient const&) =
      default;
  BigtableTableAdminClient(BigtableTableAdminClient&&) = default;
  BigtableTableAdminClient& operator=(BigtableTableAdminClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(BigtableTableAdminClient const& a,
                         BigtableTableAdminClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(BigtableTableAdminClient const& a,
                         BigtableTableAdminClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Creates a new table in the specified instance.
  /// The table can be created with a full set of initial column families,
  /// specified in the request.
  ///
  /// @param parent  Required. The unique name of the instance in which to
  /// create the table.
  ///  Values are of the form `projects/{project}/instances/{instance}`.
  /// @param table_id  Required. The name by which the new table should be
  /// referred to within the parent
  ///  instance, e.g., `foobar` rather than `{parent}/tables/foobar`.
  ///  Maximum 50 characters.
  /// @param table  Required. The Table to create.
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Table,google/bigtable/admin/v2/table.proto#L61}
  ///
  /// [google.bigtable.admin.v2.CreateTableRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L408}
  /// [google.bigtable.admin.v2.Table]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L61}
  ///
  StatusOr<google::bigtable::admin::v2::Table> CreateTable(
      std::string const& parent, std::string const& table_id,
      google::bigtable::admin::v2::Table const& table);

  ///
  /// Lists all tables served from a specified instance.
  ///
  /// @param parent  Required. The unique name of the instance for which tables
  /// should be listed.
  ///  Values are of the form `projects/{project}/instances/{instance}`.
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Table,google/bigtable/admin/v2/table.proto#L61}
  ///
  /// [google.bigtable.admin.v2.ListTablesRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L510}
  /// [google.bigtable.admin.v2.Table]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L61}
  ///
  StreamRange<google::bigtable::admin::v2::Table> ListTables(
      std::string const& parent);

  ///
  /// Gets metadata information about the specified table.
  ///
  /// @param name  Required. The unique name of the requested table.
  ///  Values are of the form
  ///  `projects/{project}/instances/{instance}/tables/{table}`.
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Table,google/bigtable/admin/v2/table.proto#L61}
  ///
  /// [google.bigtable.admin.v2.GetTableRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L553}
  /// [google.bigtable.admin.v2.Table]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L61}
  ///
  StatusOr<google::bigtable::admin::v2::Table> GetTable(
      std::string const& name);

  ///
  /// Permanently deletes a specified table and all of its data.
  ///
  /// @param name  Required. The unique name of the table to be deleted.
  ///  Values are of the form
  ///  `projects/{project}/instances/{instance}/tables/{table}`.
  ///
  /// [google.bigtable.admin.v2.DeleteTableRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L571}
  ///
  Status DeleteTable(std::string const& name);

  ///
  /// Performs a series of column family modifications on the specified table.
  /// Either all or none of the modifications will occur before this method
  /// returns, but data requests received prior to that point may see a table
  /// where only some modifications have taken effect.
  ///
  /// @param name  Required. The unique name of the table whose families should
  /// be modified.
  ///  Values are of the form
  ///  `projects/{project}/instances/{instance}/tables/{table}`.
  /// @param modifications  Required. Modifications to be atomically applied to
  /// the specified table's families.
  ///  Entries are applied in order, meaning that earlier modifications can be
  ///  masked by later ones (in the case of repeated updates to the same family,
  ///  for example).
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Table,google/bigtable/admin/v2/table.proto#L61}
  ///
  /// [google.bigtable.admin.v2.ModifyColumnFamiliesRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L585}
  /// [google.bigtable.admin.v2.Table]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L61}
  ///
  StatusOr<google::bigtable::admin::v2::Table> ModifyColumnFamilies(
      std::string const& name,
      std::vector<google::bigtable::admin::v2::ModifyColumnFamiliesRequest::
                      Modification> const& modifications);

  ///
  /// Generates a consistency token for a Table, which can be used in
  /// CheckConsistency to check whether mutations to the table that finished
  /// before this call started have been replicated. The tokens will be
  /// available for 90 days.
  ///
  /// @param name  Required. The unique name of the Table for which to create a
  /// consistency token.
  ///  Values are of the form
  ///  `projects/{project}/instances/{instance}/tables/{table}`.
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::GenerateConsistencyTokenResponse,google/bigtable/admin/v2/bigtable_table_admin.proto#L640}
  ///
  /// [google.bigtable.admin.v2.GenerateConsistencyTokenRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L626}
  /// [google.bigtable.admin.v2.GenerateConsistencyTokenResponse]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L640}
  ///
  StatusOr<google::bigtable::admin::v2::GenerateConsistencyTokenResponse>
  GenerateConsistencyToken(std::string const& name);

  ///
  /// Checks replication consistency based on a consistency token, that is, if
  /// replication has caught up based on the conditions specified in the token
  /// and the check request.
  ///
  /// @param name  Required. The unique name of the Table for which to check
  /// replication consistency.
  ///  Values are of the form
  ///  `projects/{project}/instances/{instance}/tables/{table}`.
  /// @param consistency_token  Required. The token created using
  /// GenerateConsistencyToken for the Table.
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::CheckConsistencyResponse,google/bigtable/admin/v2/bigtable_table_admin.proto#L664}
  ///
  /// [google.bigtable.admin.v2.CheckConsistencyRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L647}
  /// [google.bigtable.admin.v2.CheckConsistencyResponse]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L664}
  ///
  StatusOr<google::bigtable::admin::v2::CheckConsistencyResponse>
  CheckConsistency(std::string const& name,
                   std::string const& consistency_token);

  ///
  /// Starts creating a new Cloud Bigtable Backup.  The returned backup
  /// [long-running operation][google.longrunning.Operation] can be used to
  /// track creation of the backup. The
  /// [metadata][google.longrunning.Operation.metadata] field type is
  /// [CreateBackupMetadata][google.bigtable.admin.v2.CreateBackupMetadata]. The
  /// [response][google.longrunning.Operation.response] field type is
  /// [Backup][google.bigtable.admin.v2.Backup], if successful. Cancelling the
  /// returned operation will stop the creation and delete the backup.
  ///
  /// @param parent  Required. This must be one of the clusters in the instance
  /// in which this
  ///  table is located. The backup will be stored in this cluster. Values are
  ///  of the form `projects/{project}/instances/{instance}/clusters/{cluster}`.
  /// @param backup_id  Required. The id of the backup to be created. The
  /// `backup_id` along with
  ///  the parent `parent` are combined as {parent}/backups/{backup_id} to
  ///  create the full backup name, of the form:
  ///  `projects/{project}/instances/{instance}/clusters/{cluster}/backups/{backup_id}`.
  ///  This string must be between 1 and 50 characters in length and match the
  ///  regex [_a-zA-Z0-9][-_.a-zA-Z0-9]*.
  /// @param backup  Required. The backup to create.
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Backup,google/bigtable/admin/v2/table.proto#L317}
  ///
  /// [google.bigtable.admin.v2.CreateBackupRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L833}
  /// [google.bigtable.admin.v2.Backup]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L317}
  ///
  future<StatusOr<google::bigtable::admin::v2::Backup>> CreateBackup(
      std::string const& parent, std::string const& backup_id,
      google::bigtable::admin::v2::Backup const& backup);

  ///
  /// Gets metadata on a pending or completed Cloud Bigtable Backup.
  ///
  /// @param name  Required. Name of the backup.
  ///  Values are of the form
  ///  `projects/{project}/instances/{instance}/clusters/{cluster}/backups/{backup}`.
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Backup,google/bigtable/admin/v2/table.proto#L317}
  ///
  /// [google.bigtable.admin.v2.GetBackupRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L889}
  /// [google.bigtable.admin.v2.Backup]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L317}
  ///
  StatusOr<google::bigtable::admin::v2::Backup> GetBackup(
      std::string const& name);

  ///
  /// Updates a pending or completed Cloud Bigtable Backup.
  ///
  /// @param backup  Required. The backup to update. `backup.name`, and the
  /// fields to be updated
  ///  as specified by `update_mask` are required. Other fields are ignored.
  ///  Update is only supported for the following fields:
  ///   * `backup.expire_time`.
  /// @param update_mask  Required. A mask specifying which fields (e.g.
  /// `expire_time`) in the
  ///  Backup resource should be updated. This mask is relative to the Backup
  ///  resource, not to the request message. The field mask must always be
  ///  specified; this prevents any future fields from being erased accidentally
  ///  by clients that do not know about them.
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Backup,google/bigtable/admin/v2/table.proto#L317}
  ///
  /// [google.bigtable.admin.v2.UpdateBackupRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L873}
  /// [google.bigtable.admin.v2.Backup]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L317}
  ///
  StatusOr<google::bigtable::admin::v2::Backup> UpdateBackup(
      google::bigtable::admin::v2::Backup const& backup,
      google::protobuf::FieldMask const& update_mask);

  ///
  /// Deletes a pending or completed Cloud Bigtable backup.
  ///
  /// @param name  Required. Name of the backup to delete.
  ///  Values are of the form
  ///  `projects/{project}/instances/{instance}/clusters/{cluster}/backups/{backup}`.
  ///
  /// [google.bigtable.admin.v2.DeleteBackupRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L902}
  ///
  Status DeleteBackup(std::string const& name);

  ///
  /// Lists Cloud Bigtable backups. Returns both completed and pending
  /// backups.
  ///
  /// @param parent  Required. The cluster to list backups from.  Values are of
  /// the
  ///  form `projects/{project}/instances/{instance}/clusters/{cluster}`.
  ///  Use `{cluster} = '-'` to list backups for all clusters in an instance,
  ///  e.g., `projects/{project}/instances/{instance}/clusters/-`.
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Backup,google/bigtable/admin/v2/table.proto#L317}
  ///
  /// [google.bigtable.admin.v2.ListBackupsRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L915}
  /// [google.bigtable.admin.v2.Backup]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L317}
  ///
  StreamRange<google::bigtable::admin::v2::Backup> ListBackups(
      std::string const& parent);

  ///
  /// Gets the access control policy for a Table or Backup resource.
  /// Returns an empty policy if the resource exists but does not have a policy
  /// set.
  ///
  /// @param resource  REQUIRED: The resource for which the policy is being
  /// requested.
  ///  See the operation documentation for the appropriate value for this field.
  /// @return
  /// @googleapis_link{google::iam::v1::Policy,google/iam/v1/policy.proto#L88}
  ///
  /// [google.iam.v1.GetIamPolicyRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L113}
  /// [google.iam.v1.Policy]:
  /// @googleapis_reference_link{google/iam/v1/policy.proto#L88}
  ///
  StatusOr<google::iam::v1::Policy> GetIamPolicy(std::string const& resource);

  ///
  /// Sets the access control policy on a Table or Backup resource.
  /// Replaces any existing policy.
  ///
  /// @param resource  REQUIRED: The resource for which the policy is being
  /// specified.
  ///  See the operation documentation for the appropriate value for this field.
  /// @param policy  REQUIRED: The complete policy to be applied to the
  /// `resource`. The size of
  ///  the policy is limited to a few 10s of KB. An empty policy is a
  ///  valid policy but certain Cloud Platform services (such as Projects)
  ///  might reject them.
  /// @return
  /// @googleapis_link{google::iam::v1::Policy,google/iam/v1/policy.proto#L88}
  ///
  /// [google.iam.v1.SetIamPolicyRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L98}
  /// [google.iam.v1.Policy]:
  /// @googleapis_reference_link{google/iam/v1/policy.proto#L88}
  ///
  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      std::string const& resource, google::iam::v1::Policy const& policy);

  /**
   * Updates the IAM policy for @p resource using an optimistic concurrency
   * control loop.
   *
   * The loop fetches the current policy for @p resource, and passes it to @p
   * updater, which should return the new policy. This new policy should use the
   * current etag so that the read-modify-write cycle can detect races and rerun
   * the update when there is a mismatch. If the new policy does not have an
   * etag, the existing policy will be blindly overwritten. If @p updater does
   * not yield a policy, the control loop is terminated and kCancelled is
   * returned.
   *
   * @param resource  Required. The resource for which the policy is being
   * specified. See the operation documentation for the appropriate value for
   * this field.
   * @param updater  Required. Functor to map the current policy to a new one.
   * @param options  Optional. Options to control the loop. Expected options
   * are:
   *       - `BigtableTableAdminBackoffPolicyOption`
   * @return google::iam::v1::Policy
   */
  StatusOr<google::iam::v1::Policy> SetIamPolicy(std::string const& resource,
                                                 IamUpdater const& updater,
                                                 Options options = {});

  ///
  /// Returns permissions that the caller has on the specified Table or Backup
  /// resource.
  ///
  /// @param resource  REQUIRED: The resource for which the policy detail is
  /// being requested.
  ///  See the operation documentation for the appropriate value for this field.
  /// @param permissions  The set of permissions to check for the `resource`.
  /// Permissions with
  ///  wildcards (such as '*' or 'storage.*') are not allowed. For more
  ///  information see
  ///  [IAM Overview](https://cloud.google.com/iam/docs/overview#permissions).
  /// @return
  /// @googleapis_link{google::iam::v1::TestIamPermissionsResponse,google/iam/v1/iam_policy.proto#L141}
  ///
  /// [google.iam.v1.TestIamPermissionsRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L126}
  /// [google.iam.v1.TestIamPermissionsResponse]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L141}
  ///
  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      std::string const& resource, std::vector<std::string> const& permissions);

  ///
  /// Checks replication consistency based on a consistency token, that is, if
  /// replication has caught up based on the conditions specified in the token
  /// and the check request.
  ///
  /// @param name  Required. The unique name of the Table for which to check
  /// replication consistency.
  ///  Values are of the form
  ///  `projects/{project}/instances/{instance}/tables/{table}`.
  /// @param consistency_token  Required. The token created using
  /// GenerateConsistencyToken for the Table.
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::CheckConsistencyResponse,google/bigtable/admin/v2/bigtable_table_admin.proto#L664}
  ///
  /// [google.bigtable.admin.v2.CheckConsistencyRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L647}
  /// [google.bigtable.admin.v2.CheckConsistencyResponse]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L664}
  ///
  future<StatusOr<google::bigtable::admin::v2::CheckConsistencyResponse>>
  AsyncCheckConsistency(std::string const& name,
                        std::string const& consistency_token);

  ///
  /// Creates a new table in the specified instance.
  /// The table can be created with a full set of initial column families,
  /// specified in the request.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::CreateTableRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L408}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Table,google/bigtable/admin/v2/table.proto#L61}
  ///
  /// [google.bigtable.admin.v2.CreateTableRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L408}
  /// [google.bigtable.admin.v2.Table]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L61}
  ///
  StatusOr<google::bigtable::admin::v2::Table> CreateTable(
      google::bigtable::admin::v2::CreateTableRequest const& request);

  ///
  /// Lists all tables served from a specified instance.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::ListTablesRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L510}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Table,google/bigtable/admin/v2/table.proto#L61}
  ///
  /// [google.bigtable.admin.v2.ListTablesRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L510}
  /// [google.bigtable.admin.v2.Table]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L61}
  ///
  StreamRange<google::bigtable::admin::v2::Table> ListTables(
      google::bigtable::admin::v2::ListTablesRequest request);

  ///
  /// Gets metadata information about the specified table.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::GetTableRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L553}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Table,google/bigtable/admin/v2/table.proto#L61}
  ///
  /// [google.bigtable.admin.v2.GetTableRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L553}
  /// [google.bigtable.admin.v2.Table]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L61}
  ///
  StatusOr<google::bigtable::admin::v2::Table> GetTable(
      google::bigtable::admin::v2::GetTableRequest const& request);

  ///
  /// Permanently deletes a specified table and all of its data.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::DeleteTableRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L571}
  ///
  /// [google.bigtable.admin.v2.DeleteTableRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L571}
  ///
  Status DeleteTable(
      google::bigtable::admin::v2::DeleteTableRequest const& request);

  ///
  /// Performs a series of column family modifications on the specified table.
  /// Either all or none of the modifications will occur before this method
  /// returns, but data requests received prior to that point may see a table
  /// where only some modifications have taken effect.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::ModifyColumnFamiliesRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L585}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Table,google/bigtable/admin/v2/table.proto#L61}
  ///
  /// [google.bigtable.admin.v2.ModifyColumnFamiliesRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L585}
  /// [google.bigtable.admin.v2.Table]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L61}
  ///
  StatusOr<google::bigtable::admin::v2::Table> ModifyColumnFamilies(
      google::bigtable::admin::v2::ModifyColumnFamiliesRequest const& request);

  ///
  /// Permanently drop/delete a row range from a specified table. The request
  /// can specify whether to delete all rows in a table, or only those that
  /// match a particular prefix.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::DropRowRangeRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L486}
  ///
  /// [google.bigtable.admin.v2.DropRowRangeRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L486}
  ///
  Status DropRowRange(
      google::bigtable::admin::v2::DropRowRangeRequest const& request);

  ///
  /// Generates a consistency token for a Table, which can be used in
  /// CheckConsistency to check whether mutations to the table that finished
  /// before this call started have been replicated. The tokens will be
  /// available for 90 days.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::GenerateConsistencyTokenRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L626}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::GenerateConsistencyTokenResponse,google/bigtable/admin/v2/bigtable_table_admin.proto#L640}
  ///
  /// [google.bigtable.admin.v2.GenerateConsistencyTokenRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L626}
  /// [google.bigtable.admin.v2.GenerateConsistencyTokenResponse]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L640}
  ///
  StatusOr<google::bigtable::admin::v2::GenerateConsistencyTokenResponse>
  GenerateConsistencyToken(
      google::bigtable::admin::v2::GenerateConsistencyTokenRequest const&
          request);

  ///
  /// Checks replication consistency based on a consistency token, that is, if
  /// replication has caught up based on the conditions specified in the token
  /// and the check request.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::CheckConsistencyRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L647}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::CheckConsistencyResponse,google/bigtable/admin/v2/bigtable_table_admin.proto#L664}
  ///
  /// [google.bigtable.admin.v2.CheckConsistencyRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L647}
  /// [google.bigtable.admin.v2.CheckConsistencyResponse]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L664}
  ///
  StatusOr<google::bigtable::admin::v2::CheckConsistencyResponse>
  CheckConsistency(
      google::bigtable::admin::v2::CheckConsistencyRequest const& request);

  ///
  /// Starts creating a new Cloud Bigtable Backup.  The returned backup
  /// [long-running operation][google.longrunning.Operation] can be used to
  /// track creation of the backup. The
  /// [metadata][google.longrunning.Operation.metadata] field type is
  /// [CreateBackupMetadata][google.bigtable.admin.v2.CreateBackupMetadata]. The
  /// [response][google.longrunning.Operation.response] field type is
  /// [Backup][google.bigtable.admin.v2.Backup], if successful. Cancelling the
  /// returned operation will stop the creation and delete the backup.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::CreateBackupRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L833}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Backup,google/bigtable/admin/v2/table.proto#L317}
  ///
  /// [google.bigtable.admin.v2.CreateBackupRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L833}
  /// [google.bigtable.admin.v2.Backup]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L317}
  ///
  future<StatusOr<google::bigtable::admin::v2::Backup>> CreateBackup(
      google::bigtable::admin::v2::CreateBackupRequest const& request);

  ///
  /// Gets metadata on a pending or completed Cloud Bigtable Backup.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::GetBackupRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L889}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Backup,google/bigtable/admin/v2/table.proto#L317}
  ///
  /// [google.bigtable.admin.v2.GetBackupRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L889}
  /// [google.bigtable.admin.v2.Backup]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L317}
  ///
  StatusOr<google::bigtable::admin::v2::Backup> GetBackup(
      google::bigtable::admin::v2::GetBackupRequest const& request);

  ///
  /// Updates a pending or completed Cloud Bigtable Backup.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::UpdateBackupRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L873}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Backup,google/bigtable/admin/v2/table.proto#L317}
  ///
  /// [google.bigtable.admin.v2.UpdateBackupRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L873}
  /// [google.bigtable.admin.v2.Backup]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L317}
  ///
  StatusOr<google::bigtable::admin::v2::Backup> UpdateBackup(
      google::bigtable::admin::v2::UpdateBackupRequest const& request);

  ///
  /// Deletes a pending or completed Cloud Bigtable backup.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::DeleteBackupRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L902}
  ///
  /// [google.bigtable.admin.v2.DeleteBackupRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L902}
  ///
  Status DeleteBackup(
      google::bigtable::admin::v2::DeleteBackupRequest const& request);

  ///
  /// Lists Cloud Bigtable backups. Returns both completed and pending
  /// backups.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::ListBackupsRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L915}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Backup,google/bigtable/admin/v2/table.proto#L317}
  ///
  /// [google.bigtable.admin.v2.ListBackupsRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L915}
  /// [google.bigtable.admin.v2.Backup]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L317}
  ///
  StreamRange<google::bigtable::admin::v2::Backup> ListBackups(
      google::bigtable::admin::v2::ListBackupsRequest request);

  ///
  /// Create a new table by restoring from a completed backup. The new table
  /// must be in the same project as the instance containing the backup.  The
  /// returned table [long-running operation][google.longrunning.Operation] can
  /// be used to track the progress of the operation, and to cancel it.  The
  /// [metadata][google.longrunning.Operation.metadata] field type is
  /// [RestoreTableMetadata][google.bigtable.admin.RestoreTableMetadata].  The
  /// [response][google.longrunning.Operation.response] type is
  /// [Table][google.bigtable.admin.v2.Table], if successful.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::RestoreTableRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L336}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::Table,google/bigtable/admin/v2/table.proto#L61}
  ///
  /// [google.bigtable.admin.v2.RestoreTableRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L336}
  /// [google.bigtable.admin.v2.Table]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/table.proto#L61}
  ///
  future<StatusOr<google::bigtable::admin::v2::Table>> RestoreTable(
      google::bigtable::admin::v2::RestoreTableRequest const& request);

  ///
  /// Gets the access control policy for a Table or Backup resource.
  /// Returns an empty policy if the resource exists but does not have a policy
  /// set.
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::GetIamPolicyRequest,google/iam/v1/iam_policy.proto#L113}
  /// @return
  /// @googleapis_link{google::iam::v1::Policy,google/iam/v1/policy.proto#L88}
  ///
  /// [google.iam.v1.GetIamPolicyRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L113}
  /// [google.iam.v1.Policy]:
  /// @googleapis_reference_link{google/iam/v1/policy.proto#L88}
  ///
  StatusOr<google::iam::v1::Policy> GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const& request);

  ///
  /// Sets the access control policy on a Table or Backup resource.
  /// Replaces any existing policy.
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::SetIamPolicyRequest,google/iam/v1/iam_policy.proto#L98}
  /// @return
  /// @googleapis_link{google::iam::v1::Policy,google/iam/v1/policy.proto#L88}
  ///
  /// [google.iam.v1.SetIamPolicyRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L98}
  /// [google.iam.v1.Policy]:
  /// @googleapis_reference_link{google/iam/v1/policy.proto#L88}
  ///
  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const& request);

  ///
  /// Returns permissions that the caller has on the specified Table or Backup
  /// resource.
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::TestIamPermissionsRequest,google/iam/v1/iam_policy.proto#L126}
  /// @return
  /// @googleapis_link{google::iam::v1::TestIamPermissionsResponse,google/iam/v1/iam_policy.proto#L141}
  ///
  /// [google.iam.v1.TestIamPermissionsRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L126}
  /// [google.iam.v1.TestIamPermissionsResponse]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L141}
  ///
  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      google::iam::v1::TestIamPermissionsRequest const& request);

  ///
  /// Checks replication consistency based on a consistency token, that is, if
  /// replication has caught up based on the conditions specified in the token
  /// and the check request.
  ///
  /// @param request
  /// @googleapis_link{google::bigtable::admin::v2::CheckConsistencyRequest,google/bigtable/admin/v2/bigtable_table_admin.proto#L647}
  /// @return
  /// @googleapis_link{google::bigtable::admin::v2::CheckConsistencyResponse,google/bigtable/admin/v2/bigtable_table_admin.proto#L664}
  ///
  /// [google.bigtable.admin.v2.CheckConsistencyRequest]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L647}
  /// [google.bigtable.admin.v2.CheckConsistencyResponse]:
  /// @googleapis_reference_link{google/bigtable/admin/v2/bigtable_table_admin.proto#L664}
  ///
  future<StatusOr<google::bigtable::admin::v2::CheckConsistencyResponse>>
  AsyncCheckConsistency(
      google::bigtable::admin::v2::CheckConsistencyRequest const& request);

 private:
  std::shared_ptr<BigtableTableAdminConnection> connection_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigtable_admin
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGTABLE_ADMIN_BIGTABLE_TABLE_ADMIN_CLIENT_H
