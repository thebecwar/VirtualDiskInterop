#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	/// <summary>
	/// Contains the version of the MODIFY_VHDSET_PARAMETERS structure to use in calls to virtual disk functions.
	/// </summary>
	public enum class ModifyVhdsetVersions
	{
		/// <summary>
		/// Not Supported.
		/// </summary>
		Unspecified = MODIFY_VHDSET_UNSPECIFIED,
		
		/// <summary>
		/// The SnapshotPath member structure will be used.
		/// </summary>
		SnapshotPath = MODIFY_VHDSET_SNAPSHOT_PATH,
		
		/// <summary>
		/// The SnapshotId member structure will be used.
		/// </summary>
		RemoveSnapshot = MODIFY_VHDSET_REMOVE_SNAPSHOT,
		
		/// <summary>
		/// The DefaultFilePath member structure will be used.
		/// </summary>
		DefaultSnapshotPath = MODIFY_VHDSET_DEFAULT_SNAPSHOT_PATH,
	};
#endif
}
