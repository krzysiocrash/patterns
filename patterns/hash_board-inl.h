#ifndef MIMHEX_HASH_BOARD_INL_H_
#define MIMHEX_HASH_BOARD_INL_H_

inline Hash HashBoard::GetHash(uint position) const
{
    return position_hash[position];
}

inline const Hash * HashBoard::GetAllHash() const
{
    return position_hash;
}

inline void HashBoard::Play(uint position, uint player)
{
    rep(ii, pattern_count[position])
        position_hash[patterns[patterns_at[position][ii]].GetPosition()] ^=
        patterns[patterns_at[position][ii]].HashChange(position, player);

    return;
}

inline uint HashBoard::GetBoardSize() const
{
    return Hex::kFieldsAlignedAmount;
}

#endif
