#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public enum class OpenVirtualDiskVersions
	{
		Unspecified = OPEN_VIRTUAL_DISK_VERSION_UNSPECIFIED,
		Version1 = OPEN_VIRTUAL_DISK_VERSION_1,
		Version2 = OPEN_VIRTUAL_DISK_VERSION_2,
	};
}