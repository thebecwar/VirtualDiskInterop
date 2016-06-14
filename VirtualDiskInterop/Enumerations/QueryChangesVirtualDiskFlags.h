#pragma once

using namespace System;

namespace VirtualDiskInterop 
{
#ifdef WIN10SUPPORT
	
	/// <summary>
	/// Contains the flags for QueryChangesVirtualDisk function
	/// </summary>
	[Flags()]
	public enum class QueryChangesVirtualDiskFlags
	{
		/// <summary>
		/// No flag specified.
		/// </summary>
		None = QUERY_CHANGES_VIRTUAL_DISK_FLAG_NONE
	};
#endif
}
