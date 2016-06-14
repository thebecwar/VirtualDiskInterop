#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains the version of the virtual disk MIRROR_VIRTUAL_DISK_PARAMETERS structure used by the MirrorVirtualDisk function.
	/// </summary>
	public enum class MirrorVirtualDiskVersions
	{
		/// <summary>
		/// Unsupported
		/// </summary>
		Unspecified = MIRROR_VIRTUAL_DISK_VERSION_UNSPECIFIED,
		
		/// <summary>
		/// Use the Version1 member.
		/// </summary>
		Version1 = MIRROR_VIRTUAL_DISK_VERSION_1,
	};
}
