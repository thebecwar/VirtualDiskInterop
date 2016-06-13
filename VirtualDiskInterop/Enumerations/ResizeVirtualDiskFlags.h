#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class ResizeVirtualDiskFlags
	{
		None = RESIZE_VIRTUAL_DISK_FLAG_NONE,
		AllowUnsafeVirtualSize = RESIZE_VIRTUAL_DISK_FLAG_ALLOW_UNSAFE_VIRTUAL_SIZE,
		ResizeToSmallestSafeVirtualSize = RESIZE_VIRTUAL_DISK_FLAG_RESIZE_TO_SMALLEST_SAFE_VIRTUAL_SIZE
	};
}