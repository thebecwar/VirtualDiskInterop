using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

using VirtualDiskInterop;
using System.Security.AccessControl;

namespace VirtualDiskInteropTest
{
    class Program
    {
        static void Main(string[] args)
        {
            VirtualStorageType storageType = new VirtualStorageType();
            storageType.DeviceId = VirtualStorageDeviceTypes.Vhdx;
            storageType.VendorId = VirtualStorageType.VendorIdMicrosoft;

            VirtualDiskSafeHandle diskHandle = new VirtualDiskSafeHandle();

            string filename = @"C:\temp\test.vhdx";
            
            OpenVirtualDiskParameters readParameters = new OpenVirtualDiskParameters();
            readParameters.Version = OpenVirtualDiskVersions.Version2;
            readParameters.Version2 = new OpenVirtualDiskParametersVersion2()
            {
                GetInfoOnly = false,
                ReadOnly = false,
                ResiliencyGuid = Guid.Empty,
            };
            
            uint result = VirtualDiskApi.OpenVirtualDisk(storageType, 
                                                         filename, 
                                                         VirtualDiskAccessMasks.None, 
                                                         OpenVirtualDiskFlags.None, 
                                                         readParameters, 
                                                         diskHandle);

            RawSecurityDescriptor descriptor = new RawSecurityDescriptor("O:BAG:BAD:(A;;GA;;;WD)");
            AttachVirtualDiskParameters parameters = new AttachVirtualDiskParameters();
            parameters.Version = AttachVirtualDiskVersions.Version1;

            result = VirtualDiskApi.AttachVirtualDisk(diskHandle, descriptor, AttachVirtualDiskFlags.PermanentLifetime, 0, parameters, null);



            diskHandle.Close();
            diskHandle = null;
        }
    }
}
