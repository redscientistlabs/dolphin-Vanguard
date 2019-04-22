namespace Helpers
{
static System::String ^
    utf8StringToSystemString(std::string utf8String) {
      size_t count = utf8String.length() * sizeof(std::string::value_type);
      if (count == 0)
        return System::String::Empty;
      array<uchar> ^ bytes = gcnew array<uchar>(count);
      {
        pin_ptr<uchar> pinnedBytes = &bytes[0];
        memcpy(pinnedBytes, utf8String.c_str(), count);
      }
      return System::Text::Encoding::UTF8->GetString(bytes);
    }

static std::string systemStringToUtf8String(System::String ^ sString)
{
  array<uchar> ^ bytes = System::Text::Encoding::UTF8->GetBytes(sString);
  pin_ptr<uchar> pinnedBytes(&bytes[0]);
  return std::string(reinterpret_cast<char*>(static_cast<uchar*>(pinnedBytes)),bytes->Length);
}

}