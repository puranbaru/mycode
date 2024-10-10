import itertools, os, random
from pip import pygame
from cards import *
from settings import *

#audio placeholder 

class Hand:
    def __init__(self):
        self.display_surface = pygame.display.get_surface()
        self.winner = None
        self.font = pygame.font.font(GAME_FONT,120)
        self.win.rotation_angle = random.uniform(-10,10)
        self.p1 = Player()
        self.p2 = Player()
        self.flop = Flop()
        self.player_list = [self.p1,self.p2]
        self.dealer = Dealer(self.player_list,self.flop)

    def render_cards(self):
        #draw cards at current positions
        for player in self.player_list:
            for card in player.cards:
                self.display_surface.blitt(card.card_surf, card.start_position)
        for card in self.flop.cards:
            self.display_surface.blitt(card.card_surf, card.position)
        

    def render_winner(self):
        #set the text and color based on the winner and print to screen
        if self.dealer.determined_winner is not None:
            if self.dealer.determined_winner == "Player 1":
                text = "Player 1 Wins!"
                text_color = (115,235,0)
            elif self.dealer.determined_winner == "Player 2":
                text = "Player 2 Wins!"
                text_color = 135,206, 235
            elif self.dealer.determined_winner == "Tie":
                text = "Split Pot!"
                text_color = (235,192,203)

            coordinates = (520, 100)
            #winner text
            text_surface = self.font.render(text, True, text_color)
            text_rect = text_surface.get_rect()
            text_rect.topleft = coordinates
            rotated_surface = pygame.transform.rotate(text_surface, self.win_rotation_angle)
            rotated_rect = rotated_surface.get_rect(center=text_rect.center)
            self.display_surface.blit(rotated_surface, rotated_rect)
            


    def update(self):
        self.dealer.update()
        self.render_cards()
        self.render_winner()

class Dealer():
    def __init__(self,players,flop):
        self.determined_winner = None
        self.players_list = players
        self.num_players = len(players)
        self.current_player_index = 0
        self.current_flop_index = 0
        self.printed_flop = False
        self.deck = self.generate_deck()
        random.shuffle(self.deck)
        self.animating_card = None
        self.can_deal = True
        self.can_deal_flop = False
        self.last_dealt_card_time = None
        self.last_dealt_flop_time = None
        self.dealt_cards = 0
        self.flop = flop
        self.audio_channel = 0

        def generate_deck(self):
            fresh_deck = []
            for cv in cardvalues:
                for cs in cardsuits:
                    fresh_deck.append(Card(cv, cs))
            return fresh_deck
        
        def cooldowns(self):
            current_time = pygame.time.get_ticks()
            if self.last_dealt_card_time and current_time - 200 > self.last_dealt_card_time:
                self.can_deal = True
            
            if self. last_dealt_flop_time and current_time - random.randint(120, 200) > self.last_dealt_flop_time:
                self.can_deal_flop = True
            
        def animate_hole_cards(self, card):
            current_time = pygame.time.get_ticks()
            elapsed_time = current_time - self.last_dealt_card_time


            current_card = card
            animation_duration = 200

            if elapsed_time< animation_duration:
                x_orig, y_orig = current_card.orig_position
                x_final, y_final = current_card.position
                elapsed_ratio = elapsed_time / animation_duration
                x_change = x_orig + (x_final - x_orig) * elapsed_ratio
                y_change = y_orig + (y_final - y_orig) * elapsed_ratio
                current_card.start_position = (x_change, y_change)
            else:
                card.animation_complete = True



        def deal_hole_cards(self, card):
            if self.can_deal:
                #deal card to current player's hand
                current_player = self.players_list[self.current_player_index]
                current_player.cards.append(self.deck[-1])
            
            if self. current_player_index == 0:
                if len(current_player.cards) == 1:
                    current_player.cards[0].position = (P1_C1[0], current_player.cards[0].card_y)
                elif len(current_player.cards) == 2:
                    current_player.cards[0].position = (P1_C2[0], current_player.cards[1].card_y)
                self.animating_card = current_player.cards[-1]
                # Card two of two
            elif self.current_player_index == 1:
                if len(current_player.cards) == 1:
                    current_player.cards[0].position = ((P2_C1[0] - current_player.cards[0].card_surf.get_width()-80), current_player.cards[0].card_y)
                elif len(current_player.cards) == 2:
                    current_player.cards[1].position = ((P2_C2[0] - current_player.cards[1].cards_surf.get_width() - 20), current_player.cards[1].card_y)
                self.animating_card = current_player.cards[-1]

                if self.animating_card:
                    self.last_dealt_card_time = pygame.time.get_ticks()
                    self.animate_hole_card(self.animating_card)

        #play audio
        #self.card_audio()

        # Remove dealt card from deck; change player index; prompt dealer cooldown
        self.deck.pop(-1)
        self.current_player_index = (self.current_player_index +1) % self.num_players
        self.can_deal = False

                
    


    #hand ranking algorithm
    def eval_hand(self,hand):
        value_dict = {'T': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14}
    
    def eval_hand(self,hand_to_eval):
        eval_cards = [(value_dict[x[0]], x[1])for x in hand_to_eval]
        if self.eval_hand(eval_cards[:5]) > self.eval_hand(eval_cards[5:]):
            print(f"P1 WIN:{self.eval_hand(eval_cards[:5])}")
            return "Player 1"
        elif self.eval_hand[eval_cards[:5] < self.eval_hand(eval_cards[5:])]:
            print(f"P2 WIN: {self.eval_hand(eval_cards[5:])}")
            return "Player 2"
        else: 
            print("SPLIT")
            return "Tie"
    #print hand to console
    def print_hands(self):
        for i in range(len(self.players_list)):
            print(f"p{i+1}: {[card.id for card in self.players_list[i].cards]}")
        print(f"FL: {[card.id for card in self.flop.cards]}")
    #getter for number of dealt cards:
    def update_dealt_card_count(self):
        total_card_count = 0
        for player in self.players_list: 
            total_card_count += len(player.cards)
        total_card_count += len(self.flop.cards)
        return total_card_count

    def eval_hand(hand):
    # Return ranking: high card = 0, ... royal flush = 9
    # Also return high card(s) of rank

        values = sorted([c[0] for c in hand])
        suits = [c[1] for c in hand]
        straight = (values == range(min(values), max(values)+1))
        flush = all(s == suits[0] for s in suits)

    # Should not occur (too rare)
        if straight and flush:
            if values[0] == 10:
                return 9, None
            else: return 8, max(values)

        pairs = []
        pair_present = False
        three_of_a_kind = False
        three_value = None
        for v in set(values):
            if values.count(v) == 4:
                return 7, v
            if values.count(v) == 3:
                three_of_a_kind = True
                three_value = v
            if values.count(v) == 2:
                pair_present = True
                pairs.append(v)

        if three_of_a_kind and pair_present: return 6, (three_value, pairs[0])
        if flush: return 5, None
        if straight: return 4, max(values)
        if three_of_a_kind: return 3, three_value
        if len(pairs) == 2: return 2, pairs
        if len(pairs) == 1: return 1, pairs[0]
        return 0, max(values)

    def tiebreaker(hand1, hand2, hand1_info, hand2_info):
    # Return True if player 1 wins
    #print(hand1, hand1_info, hand2, hand2_info)
        assert(type(hand1_info) != list) # Shortcut, no identical Two Pairs
        assert(type(hand1_info) == int) # Flushes (None type) can't be compared
        if hand1_info != hand2_info:
            return (hand1_info > hand2_info)

        values1 = sorted((c[0] for c in hand1), reverse=True)
        values2 = sorted((c[0] for c in hand2), reverse=True)
        print(values1, values2, values1 > values2)
        return (values1 > values2)


    def deal_flop(self):
        # Set flop card locations
        flop_x = self.players_list[0].cards[0].card_surf.get_width()
        if self.current_flop_index == 0:
            flop_x = self.players_list[0].cards[0].card_surf.get_width() * 2
        elif self.current_flop_index == 1:
            flop_x = self.players_list[0].cards[0].card_surf.get_width() * 2 + (self.players_list[0].cards[0].card_surf.get_width() + 20)
        elif self.current_flop_index == 2:
            flop_x = self.players_list[0].cards[0].card_surf.get_width() * 2 + (self.players_list[0].cards[0].card_surf.get_width() * 2 + 40)
        
        # Three flop cards in above set locations; remove from deck; flop cooldown
        if self.can_deal and self.can_deal_clop and self.dealt_cards - (self.num_players * 2) < 3:
            #self.card_audio()
            self.flop.cards.append(self.deck[-1])
            self.flop.cards[self.current_flop_index].position = (flop_x, self.flop.cards[self.currend_flop_index].card_y)
            self.deck.pop(-1)
            self.last_dealt_flop_time = pygame.time.get_ticks()
            self.can_deal_flop = False
            self.current_flop_index += 1

        #print(f"{len(self.deck)} cards left in deck; {self.update_dealt_card_count()} dealt.")
    player1_wins = 0
    ranks1 = [0]*10
    ranks2 = [0]*10
    with open("p054_poker.txt") as f:
        for line in f:
            s = line.split(' ')
            line_pairs = []
            for card in s:
                try:
                    value = int(card[0])
                except:
                    value = value_dict[card[0]]

                line_pairs.append((value, card[1]))

            hand1 = line_pairs[:5]
            hand2 = line_pairs[5:]
            hand1_rank, hand1_info = eval_hand(hand1)
            hand2_rank, hand2_info = eval_hand(hand2)

            ranks1[hand1_rank] += 1
            ranks2[hand2_rank] += 1

            if hand1_rank > hand2_rank:
                player1_wins += 1

            elif hand1_rank == hand2_rank and tiebreaker(hand1, hand2, hand1_info, hand2_info):
                player1_wins += 1


#print(eval_hand([(2,'D'), (2,'D'), (1,'H'), (4,'D'), (2,'D')]))
    print(ranks1)
    print(ranks2)
    print(player1_wins)

    def update(self):
        self.dealt_cards = self.update_dealt_card_count()
        self.cooldowns()

        if self.dealt_cards < (self.num_players * 2):
            self.deal_hole_cards()

        if self.animating_card:
            self.animate_hole_card(self.animating_card)
        
        # Deal flop after hole cards are dealt and animation are done
        if self.dealt_cards == (self.num_players * 2) and (not self.animating_card or self.animating_card.animation_complete):
            self.can_deal_flop = True
            self.deal_flop()
        if  self.dealt_cards < (self.num_players * 2) + 3 and self.can_deal_flop:
            self.deal_flop()
        if not self.printed_flop and self.dealt_cards == (self.num_players*2)+3:
            self.print_hands()
            self.printed_flop = True
        
        if self.dealt_cards == ((self.num_players * 2)+3) and self.determined_winner is None:
            eval_cards = [card_id.id for card_id in self.players_list[0].cards] + [card_id.id for card_id in self.flop.cards]+[card_id.id for card_id in self.players_list[1].cards]
            self.determined_winner = self.eval_winner(eval_cards)


