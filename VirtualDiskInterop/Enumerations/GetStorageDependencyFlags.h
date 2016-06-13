#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class GetStorageDependencyFlags
	{
		None = GET_STORAGE_DEPENDENCY_FLAG_NONE,
		HostVolumes = GET_STORAGE_DEPENDENCY_FLAG_HOST_VOLUMES,
		DiskHandle = GET_STORAGE_DEPENDENCY_FLAG_DISK_HANDLE,
	};
}