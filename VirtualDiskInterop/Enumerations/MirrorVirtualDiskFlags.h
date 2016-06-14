#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains virtual hard disk (VHD) mirror request flags.
	/// </summary> 
	[Flags()]
	public enum class MirrorVirtualDiskFlags
	{
		/// <summary>
		/// The mirror virtual disk file does not exist, and needs to be created.
		/// </summary>
		None = MIRROR_VIRTUAL_DISK_FLAG_NONE,
		
		/// <summary>
		/// Create the mirror using an existing file.
		/// </summary>
		ExistingFile = MIRROR_VIRTUAL_DISK_FLAG_EXISTING_FILE,
	};
}
