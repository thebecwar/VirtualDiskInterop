#pragma once

using namespace System;

namespace VirtualDiskInterop 
{
#ifdef WIN10SUPPORT
	
	/// <summary>
	/// Contains flags affecting the behavior of the ApplySnapshotVhdSet function.
	/// </summary>
	[Flags()]
	public enum class ApplySnapshotVhdsetFlags
	{
		/// <summary>
		/// No flag specified.
		/// </summary>
		None = APPLY_SNAPSHOT_VHDSET_FLAG_NONE,
		
		/// <summary>
		/// Indicates that the snapshot to be applied was created as a writeable snapshot type.
		/// </summary>
		Writable = APPLY_SNAPSHOT_VHDSET_FLAG_WRITEABLE
	};
#endif
}
