


struct block{

      int difficulty;
      int block_version;
      int amount; //in signature
      int timestamp; //in signature
      char senders_address[6]; //in signature
      char recivers_address[6];
      char senders_signature[6];
      //int block_no; 

      
}
void write_block(void);

