#pragma once

void AssociateCard(int card_id, int card[2]){
    int card_color = (card_id + 1) / 13;
    int card_number = card_id - (13 * (card_color));
    
    card[0] = card_color;
    card[1] = card_number;
    
}

void ShowCard(int card_id) {
    const char card_name[13][7] = {"AS", "ROI", "DAME", "VALET", "DIX", "NEUF", "HUIT", "SEPT", "SIX", "CINQ", "QUATRE", "TROIS", "DEUX"};
    const char card_color[4][8] = {"PIQUE", "COEUR", "CARREAU", "TREFLE"};
    
    int card[2];
    AssociateCard(card_id, card);
    
    printf("%s de %s\n",  card_name[card[1]], card_color[card[0]]);
    
}

