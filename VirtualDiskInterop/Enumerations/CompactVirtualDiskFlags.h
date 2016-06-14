#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual hard disk (VHD) compact request flags.
	/// </summary>
	[Flags()]
	public enum class CompactVirtualDiskFlags
	{
		None = COMPACT_VIRTUAL_DISK_FLAG_NONE,
		NoZeroScan = COMPACT_VIRTUAL_DISK_FLAG_NO_ZERO_SCAN,
		NoBlockMoves = COMPACT_VIRTUAL_DISK_FLAG_NO_BLOCK_MOVES
	};
}
