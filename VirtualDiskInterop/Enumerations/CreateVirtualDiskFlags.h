#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class CreateVirtualDiskFlags
	{
		None = CREATE_VIRTUAL_DISK_FLAG_NONE,
		FullPhysicalAllocation = CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION,
		PreventWritesToSourceDisk = CREATE_VIRTUAL_DISK_FLAG_PREVENT_WRITES_TO_SOURCE_DISK,
		DoNotCopyMetadataFromParent = CREATE_VIRTUAL_DISK_FLAG_DO_NOT_COPY_METADATA_FROM_PARENT
	};
}