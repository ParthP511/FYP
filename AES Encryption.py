function aes_encrypt(plaintext: bytes, key: bytes) -> bytes: # Perform key expansion to generate the round keys round_keys = key_expansion(key)
# Pad the plaintext to a multiple of the block size plaintext = pad_plaintext(plaintext)
# Split the plaintext into blocks of the block size plaintext_blocks = split_blocks(plaintext, block_size) # Initialize an empty ciphertext buffer
ciphertext = []
# Encrypt each plaintext block for block in plaintext_blocks:
# Perform the initial round
state = add_round_key(block, round_keys[:block_size])
# Perform the specified number of rounds for i in range(1, num_rounds):
state = sub_bytes(state)
state = shift_rows(state)
state = mix_columns(state)
state = add_round_key(state, round_keys[i*block_size:(i+1)*block_size])
# Perform the final round
state = sub_bytes(state)
state = shift_rows(state)
state = add_round_key(state, round_keys[num_rounds*block_size:])
# Append the ciphertext block to the ciphertext buffer
ciphertext.append(state)
# Concatenate the ciphertext blocks and return the ciphertext return concatenate_blocks(ciphertext)
