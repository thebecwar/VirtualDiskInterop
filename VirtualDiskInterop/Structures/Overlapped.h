#pragma once

using namespace System;
using namespace System::Threading;

namespace VirtualDiskInterop
{
	///<summary>Wrapper around the WinApi OVERLAPPED structure</summary>
	public ref class Overlapped
	{
	public:
		Overlapped()
		{
			this->m_Overlapped = new OVERLAPPED();
			this->m_Overlapped->Internal = 0;
			this->m_Overlapped->InternalHigh = 0;
			this->m_Overlapped->Offset = 0;
			this->m_Overlapped->OffsetHigh = 0;
			this->m_Overlapped->Pointer = 0;

			this->m_WaitHandle = gcnew ManualResetEvent(false);
			this->m_Overlapped->hEvent = this->m_WaitHandle->SafeWaitHandle->DangerousGetHandle().ToPointer();
		}
		~Overlapped()
		{
			if (this->m_Overlapped != NULL)
			{
				delete this->m_Overlapped;
				this->m_Overlapped = NULL;
			}
			if (this->m_WaitHandle != nullptr)
			{
				delete this->m_WaitHandle;
				this->m_WaitHandle = nullptr;
			}
		}

		property ManualResetEvent^ WaitHandle
		{
			ManualResetEvent^ get()
			{
				return this->m_WaitHandle;
			}
		}
		property UIntPtr Internal
		{
			UIntPtr get()
			{
				if (this->m_Overlapped != NULL)
				{
					return UIntPtr(this->m_Overlapped->Internal);
				}
				return UIntPtr::Zero;
			}
			void set(UIntPtr value)
			{
				if (this->m_Overlapped != NULL)
				{
					this->m_Overlapped->Internal = (ULONG_PTR)value.ToPointer();
				}
			}
		}
		property UIntPtr InternalHigh
		{
			UIntPtr get()
			{
				if (this->m_Overlapped != NULL)
				{
					return UIntPtr(this->m_Overlapped->InternalHigh);
				}
				return UIntPtr::Zero;
			}
			void set(UIntPtr value)
			{
				if (this->m_Overlapped != NULL)
				{
					this->m_Overlapped->InternalHigh = (ULONG_PTR)value.ToPointer();
				}
			}
		}
		property unsigned int Offset
		{
			unsigned int get()
			{
				if (this->m_Overlapped != NULL)
				{
					return this->m_Overlapped->Offset;
				}
				return 0;
			}
			void set(unsigned int value)
			{
				if (this->m_Overlapped != NULL)
				{
					this->m_Overlapped->Offset = value;
				}
			}
		}
		property unsigned int OffsetHigh
		{
			unsigned int get()
			{
				if (this->m_Overlapped != NULL)
				{
					return this->m_Overlapped->OffsetHigh;
				}
				return 0;
			}
			void set(unsigned int value)
			{
				if (this->m_Overlapped != NULL)
				{
					this->m_Overlapped->OffsetHigh = value;
				}
			}
		}
		property IntPtr Pointer
		{
			IntPtr get()
			{
				if (this->m_Overlapped != NULL)
				{
					return IntPtr(this->m_Overlapped->Pointer);
				}
				return IntPtr::Zero;
			}
			void set(IntPtr value)
			{
				if (this->m_Overlapped != NULL)
				{
					this->m_Overlapped->Pointer = value.ToPointer();
				}
			}
		}

	internal:
		property OVERLAPPED* NativeOverlapped
		{
			OVERLAPPED* get()
			{
				return this->m_Overlapped;
			}
		}

	private:
		// Managed
		ManualResetEvent^ m_WaitHandle;
		// Unmanaged
		OVERLAPPED* m_Overlapped;

	};
}