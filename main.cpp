#include <clickhouse/client.h>
#include <iostream>

int main() {
    try {
        // Set up the connection to ClickHouse
        clickhouse::Client client("localhost", 9000);  // Default ClickHouse server and port

        // Example query: Select server version
        std::string query = "SELECT version()";
        clickhouse::Block block;
        client.select(query, block);

        // Print the result
        for (size_t row = 0; row < block.GetRowCount(); ++row) {
            std::cout << block[0].As<std::string>(row) << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
