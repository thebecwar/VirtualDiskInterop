#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public enum class MergeVirtualDiskVersions
	{
		Unspecified = MERGE_VIRTUAL_DISK_VERSION_UNSPECIFIED,
		Version1 = MERGE_VIRTUAL_DISK_VERSION_1,
		Version2 = MERGE_VIRTUAL_DISK_VERSION_2,
	};
}