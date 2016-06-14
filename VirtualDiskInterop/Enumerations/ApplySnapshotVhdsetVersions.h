#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	/// <summary>
	/// Enumerates the possible versions for parameters for the ApplySnapshotVhdSet function.
	/// </summary>
	public enum class ApplySnapshotVhdsetFlags
	{
		/// <summary>
		/// Not Supported.
		/// </summary>
		Unspecified = APPLY_SNAPSHOT_VHDSET_VERSION_UNSPECIFIED,
		
		/// <summary>
		/// The Version1 member structure will be used.
		/// </summary>
		Version1 = APPLY_SNAPSHOT_VHDSET_VERSION_1
	};
#endif
}
