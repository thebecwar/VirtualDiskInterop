#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	/// <summary>
	/// Contains the version of the DELETE_SNAPHSOT_VHDSET_PARAMETERS structure to use in calls to virtual disk functions.
	/// </summary>
	public enum class DeleteSnapshotVhdsetVersions
	{
		/// <summary>
		/// Not supported.
		/// </summary>
		Unspecified = DELETE_SNAPSHOT_VHDSET_VERSION_UNSPECIFIED,
		
		/// <summary>
		/// The Version1 member structure will be used.
		/// </summary>
		Version1 = DELETE_SNAPSHOT_VHDSET_VERSION_1
	};
#endif
}
