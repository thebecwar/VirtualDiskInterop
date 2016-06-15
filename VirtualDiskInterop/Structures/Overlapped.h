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
		
	private:
		// Managed
		ManualResetEvent^ m_WaitHandle;

		// Unmanaged
		OVERLAPPED* m_Overlapped;


	};
}