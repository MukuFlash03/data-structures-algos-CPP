import uuid
import base64

# Replace this with your actual BinData value from MongoDB
bin_data_str1 = "JR4fbPA8STGGY1/IY8g6kg=="
bin_data_str2 = "5m0KOkMWTZ2sZu43VAgdCQ=="

# Decode the BinData string from base64 to bytes
bin_data_bytes1 = base64.b64decode(bin_data_str1)
bin_data_bytes2 = base64.b64decode(bin_data_str2)

# Create a UUID object from the bytes
uuid_obj1 = uuid.UUID(bytes=bin_data_bytes1, version=4)
uuid_obj2 = uuid.UUID(bytes=bin_data_bytes2, version=4)

# Print the UUID
print(uuid_obj1)
print(uuid_obj2)