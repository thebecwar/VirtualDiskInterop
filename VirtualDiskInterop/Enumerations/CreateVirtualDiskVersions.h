#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public enum class CreateVirtualDiskVersions
	{
		Unspecified = CREATE_VIRTUAL_DISK_VERSION_UNSPECIFIED,
		Version1 = CREATE_VIRTUAL_DISK_VERSION_1,
		Version2 = CREATE_VIRTUAL_DISK_VERSION_2,
	};
}