#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	/// <summary>
	/// Contains flags affecting the behavior of the ModifyVhdSet function.
	/// </summary>
	[Flags()]
	public enum class ModifyVhdsetFlags
	{
		/// <summary>
		/// No flag specified.
		/// </summary>
		None = MODIFY_VHDSET_FLAG_NONE,
		
		WriteableSnapshot = MODIFY_VHDSET_FLAG_WRITEABLE_SNAPSHOT
	};
#endif
}
