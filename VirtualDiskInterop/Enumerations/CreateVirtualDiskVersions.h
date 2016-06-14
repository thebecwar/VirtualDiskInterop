#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains the version of the virtual hard disk (VHD) CreateVirtualDiskParameters structure to use in calls to VHD functions.
	/// </summary>
	public enum class CreateVirtualDiskVersions
	{
		Unspecified = CREATE_VIRTUAL_DISK_VERSION_UNSPECIFIED,
		Version1 = CREATE_VIRTUAL_DISK_VERSION_1,
		Version2 = CREATE_VIRTUAL_DISK_VERSION_2,
#ifdef WIN10SUPPORT
		Version3 = CREATE_VIRTUAL_DISK_VERSION_3
#endif
	};
}
