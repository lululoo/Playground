using System;

namespace NETStandardLibrary
{
    public interface ILegacyApplication
    {
        string GetAuthToken();

        string CommonDirectory { get; }
    }
}
