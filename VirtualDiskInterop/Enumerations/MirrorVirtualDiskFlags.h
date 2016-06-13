#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class MirrorVirtualDiskFlags
	{
		None = MIRROR_VIRTUAL_DISK_FLAG_NONE,
		ExistingFile = MIRROR_VIRTUAL_DISK_FLAG_EXISTING_FILE,
	};
}