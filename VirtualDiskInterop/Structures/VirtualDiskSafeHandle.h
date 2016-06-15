#pragma once

using namespace System;
using namespace Microsoft::Win32::SafeHandles;

namespace VirtualDiskInterop
{
	///<summary></summary>
	public ref class VirtualDiskSafeHandle : public SafeHandleMinusOneIsInvalid
	{
	internal:
		///<summary>Internal Use Only</summary>
		VirtualDiskSafeHandle(HANDLE hDisk) : SafeHandleMinusOneIsInvalid(true)
		{
			this->SetHandle(IntPtr(hDisk));
		}
		///<summary>Internal Use Only</summary>
		void SetHandle(HANDLE value)
		{
			this->SetHandle(IntPtr(value));
		}
	public:
		///<summary>Creates a new <see cref="VirtualDiskSafeHandle"></summary>
		VirtualDiskSafeHandle() : SafeHandleMinusOneIsInvalid(true)
		{
		}
		///<summary>Creates a new <see cref="VirtualDiskSafeHandle"> using an existing handle.</summary>
		///<param name="VirtualDiskHandle">Existing handle value</param>
		VirtualDiskSafeHandle(IntPtr VirtualDiskHandle) : SafeHandleMinusOneIsInvalid(true)
		{
			this->SetHandle(VirtualDiskHandle);
		}
		
		// Inherited via SafeHandleMinusOneIsInvalid

		///<summary>executes the code required to free the handle.</summary>
		///<return>
		/// true if the handle is released successfully; otherwise, in the event of a 
		/// catastrophic failure, false. In this case, it generates a releaseHandleFailed 
		/// MDA Managed Debugging Assistant.
		/// </return>
		virtual bool ReleaseHandle() override
		{
			if (!this->IsInvalid)
			{
				HANDLE hDisk = this->DangerousGetHandle().ToPointer();
				BOOL ok = CloseHandle(hDisk);
				this->SetHandleAsInvalid();
				return ok != 0;
			}
			return true;
		}

	};
}