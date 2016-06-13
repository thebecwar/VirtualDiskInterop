#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class OpenVirtualDiskFlags
	{
		None = OPEN_VIRTUAL_DISK_FLAG_NONE,
		NoParents = OPEN_VIRTUAL_DISK_FLAG_NO_PARENTS,
		BlankFile = OPEN_VIRTUAL_DISK_FLAG_BLANK_FILE,
		BootDrive = OPEN_VIRTUAL_DISK_FLAG_BOOT_DRIVE,
		CachedIO = OPEN_VIRTUAL_DISK_FLAG_CACHED_IO,
		CustomDiffChain = OPEN_VIRTUAL_DISK_FLAG_CUSTOM_DIFF_CHAIN,
	};
}