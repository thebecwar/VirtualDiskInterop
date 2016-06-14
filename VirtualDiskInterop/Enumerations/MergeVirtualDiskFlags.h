#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual hard disk (VHD) merge request flags.
	/// </summary>
	[Flags()]
	public enum class MergeVirtualDiskFlags
	{
		None = MERGE_VIRTUAL_DISK_FLAG_NONE,
	};
}
