#pragma once

using namespace System;

namespace VirtualDiskInterop 
{
#ifdef WIN10SUPPORT
	[Flags()]
	public enum class ApplySnapshotVhdsetFlags
	{
		None = APPLY_SNAPSHOT_VHDSET_FLAG_NONE,
		Writable = APPLY_SNAPSHOT_VHDSET_FLAG_WRITEABLE
	};
#endif
}
