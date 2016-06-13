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
	};
}