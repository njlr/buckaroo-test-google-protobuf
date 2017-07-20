#include <iostream>
#include <fstream>
#include <string>
#include <gtest/gtest.h>

#include "addressbook.pb.h"

TEST(protobuf, basicreadwrite) {

  tutorial::AddressBook address_book;

  {
    // Read the existing address book.
    std::fstream input("address_book.txt", std::ios::in | std::ios::binary);
    if (!address_book.ParseFromIstream(&input)) {
      std::cerr << "Failed to parse address book." << std::endl;
      ASSERT_TRUE(false);
    }
  }

  // We expect the file to have some fixed data inside.
  // Verify that it is as expected.
  ASSERT_TRUE(address_book.people_size() == 1);
  ASSERT_TRUE(address_book.people(0).id() == 1234);
  ASSERT_TRUE(address_book.people(0).name() == "fred");
  ASSERT_TRUE(address_book.people(0).email() == "fred@example.com");
}
