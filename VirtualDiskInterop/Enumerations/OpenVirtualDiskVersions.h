#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains the version of the virtual hard disk (VHD) OPEN_VIRTUAL_DISK_PARAMETERS structure to use in calls to VHD functions.
	/// </summary>
	public enum class OpenVirtualDiskVersions
	{
		Unspecified = OPEN_VIRTUAL_DISK_VERSION_UNSPECIFIED,
		Version1 = OPEN_VIRTUAL_DISK_VERSION_1,
		Version2 = OPEN_VIRTUAL_DISK_VERSION_2,
		Version3 = OPEN_VIRTUAL_DISK_VERSION_3
	};
}
