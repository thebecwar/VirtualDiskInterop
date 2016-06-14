#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	/// <summary>
	/// Contains flags affecting the behavior of the DeleteSnapshotVhdSet function.
	/// </summary>
	public enum class DeleteSnapshotVhdsetFlags
	{
		/// <summary>
		/// No flag specified.
		/// </summary>
		None = DELETE_SNAPSHOT_VHDSET_FLAG_NONE,
		
		/// <summary>
		/// A reference point should be persisted in the VHD Set after the snapshot is deleted.
		/// </summary>
		PersistRCT = DELETE_SNAPSHOT_VHDSET_FLAG_PERSIST_RCT,
	};
#endif
}
