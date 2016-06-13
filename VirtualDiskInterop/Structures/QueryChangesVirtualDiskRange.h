#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class QueryChangesVirtualDiskRange
	{
	public:
		property unsigned long long ByteOffset
		{
			unsigned long long get()
			{
				return this->m_ByteOffset;
			}
			void set(unsigned long long value)
			{
				this->m_ByteOffset = value;
			}
		}
		property unsigned long long ByteLength
		{
			unsigned long long get()
			{
				return this->m_ByteLength;
			}
			void set(unsigned long long value)
			{
				this->m_ByteLength = value;
			}
		}
		property unsigned long long Reserved
		{
			unsigned long long get()
			{
				return this->m_Reserved;
			}
			void set(unsigned long long)
			{
				throw gcnew NotSupportedException("Cannot set reserved parameter.");
			}
		}
	private:
		unsigned long long m_ByteOffset;
		unsigned long long m_ByteLength;
		unsigned long long m_Reserved = 0;
	};
}