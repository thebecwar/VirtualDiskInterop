#pragma once
using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Enumerates the possible versions for parameters for the ResizeVirtualDisk function.
	/// </summary>
	public enum class ResizeVirtualDiskVersions
	{
		/// <summary>
		/// The version is not valid.
		/// </summary>
		Unspecified = RESIZE_VIRTUAL_DISK_VERSION_UNSPECIFIED,
		
		/// <summary>
		/// Version one of the parameters is used. This is the only supported value.
		/// </summary>
		Version1 = RESIZE_VIRTUAL_DISK_VERSION_1,
	};
}
