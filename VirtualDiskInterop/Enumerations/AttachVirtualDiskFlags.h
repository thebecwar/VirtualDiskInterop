#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class AttachVirtualDiskFlags
	{
		None = ATTACH_VIRTUAL_DISK_FLAG_NONE,
		ReadOnly = ATTACH_VIRTUAL_DISK_FLAG_READ_ONLY,
		NoDriveLetter = ATTACH_VIRTUAL_DISK_FLAG_NO_DRIVE_LETTER,
		PermanentLifetime = ATTACH_VIRTUAL_DISK_FLAG_PERMANENT_LIFETIME,
		NoLocalHost = ATTACH_VIRTUAL_DISK_FLAG_NO_LOCAL_HOST
	};

}
