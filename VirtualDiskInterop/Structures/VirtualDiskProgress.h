#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class VirtualDiskProgress
	{
	public:
		property unsigned int OperationStatus
		{
			unsigned int get()
			{
				return this->m_OperationStatus;
			}
			void set(unsigned int value)
			{
				this->m_OperationStatus = value;
			}
		}
		property unsigned long long CurrentValue
		{
			unsigned long long get()
			{
				return this->m_CurrentValue;
			}
			void set(unsigned long long value)
			{
				this->m_CurrentValue = value;
			}
		}
		property unsigned long long CompletionValue
		{
			unsigned long long get()
			{
				return this->m_CompletionValue;
			}
			void set(unsigned long long value)
			{
				this->m_CompletionValue = value;
			}
		}
	private:
		unsigned int m_OperationStatus;
		unsigned long long m_CurrentValue;
		unsigned long long m_CompletionValue;
	internal:
		VIRTUAL_DISK_PROGRESS* m_NativeData = NULL;
		VIRTUAL_DISK_PROGRESS* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
			this->m_NativeData = new VIRTUAL_DISK_PROGRESS();
			this->m_NativeData->OperationStatus = this->m_OperationStatus;
			this->m_NativeData->CurrentValue = this->m_CurrentValue;
			this->m_NativeData->CompletionValue = this->m_CompletionValue;
			return this->m_NativeData;
		}
		void ReleaseNative(bool updateData)
		{
			if (this->m_NativeData)
			{
				if (updateData)
				{
					this->m_OperationStatus = this->m_NativeData->OperationStatus;
					this->m_CurrentValue = this->m_NativeData->CurrentValue;
					this->m_CompletionValue = this->m_NativeData->CompletionValue;
				}

				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
		}

	};
}