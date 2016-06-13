#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public enum class SetVirtualDiskInfoVersions
	{
		Unspecified = SET_VIRTUAL_DISK_INFO_UNSPECIFIED,
		ParentPath = SET_VIRTUAL_DISK_INFO_PARENT_PATH,
		Identifier = SET_VIRTUAL_DISK_INFO_IDENTIFIER,
		ParentPathWithDepth = SET_VIRTUAL_DISK_INFO_PARENT_PATH_WITH_DEPTH,
		PhysicalSectorSize = SET_VIRTUAL_DISK_INFO_PHYSICAL_SECTOR_SIZE,
		VirtualDiskID = SET_VIRTUAL_DISK_INFO_VIRTUAL_DISK_ID,
#if WIN10SUPPORT
		ChangeTrackingState = SET_VIRTUAL_DISK_INFO_CHANGE_TRACKING_STATE,
		ParentLocation = SET_VIRTUAL_DISK_INFO_PARENT_LOCATOR,
#endif
	};
}