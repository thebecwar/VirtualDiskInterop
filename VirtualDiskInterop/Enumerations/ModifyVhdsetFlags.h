#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	[Flags()]
	public enum class ModifyVhdsetFlags
	{
		None = MODIFY_VHDSET_FLAG_NONE,
	};
#endif
}