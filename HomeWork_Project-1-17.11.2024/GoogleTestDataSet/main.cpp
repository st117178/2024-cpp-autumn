#include <iostream>
#include <gtest/gtest.h>
#include "../src/Dataset.h"

TEST(Data_Set, Test_Operator_Double_Sq)
{
    Dataset dataset("../data_set_file/file1.txt", 0);

    void *data = dataset[1][2].data;

    float dataset_data = *static_cast<float *>(data);

    float result = 4.11;

    ASSERT_EQ(dataset_data, result);
}

TEST(Data_Set, Test_Data_Type)
{
    Dataset dataset("../data_set_file/file1.txt", 0);

    DataType integer = dataset[0][0].type;
    DataType string1 = dataset[0][1].type;
    DataType floatn = dataset[0][2].type;
    DataType string2 = dataset[0][3].type;

    ASSERT_EQ(integer, DataType::INT);
    ASSERT_EQ(string1, DataType::STRING);
    ASSERT_EQ(floatn, DataType::FLOAT);
    ASSERT_EQ(string2, DataType::STRING);
}

TEST(Data_Set, Test_Size_Data_Set)
{
    Dataset dataset("../data_set_file/file1.txt", 0);

    int size = dataset.getSizeDataSet();

    ASSERT_EQ(size, 12);
}

TEST(Data_Set, Test_Size_Column)
{
    Dataset dataset("../data_set_file/file1.txt", 0);

    int countel_line1 = dataset[0].getLen();
    int countel_line2 = dataset[1].getLen();
    int countel_line3 = dataset[2].getLen();

    ASSERT_EQ(countel_line1, 4);
    ASSERT_EQ(countel_line2, 4);
    ASSERT_EQ(countel_line3, 4);
}

TEST(Data_Set, Test_Stream_Node)
{
    Dataset dataset("../data_set_file/file1.txt", 0);

    std::stringstream stream_dataset;
    stream_dataset << dataset[0][1];

    std::string result = "apple";
    std::stringstream stream_result;
    stream_result << result;

    ASSERT_EQ(stream_dataset.str(), stream_result.str());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
