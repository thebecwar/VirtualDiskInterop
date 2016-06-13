#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	[Flags()]
	public enum class TakeSnapshotVhdsetFlags
	{
		None = TAKE_SNAPSHOT_VHDSET_FLAG_NONE,
	};
#endif
}