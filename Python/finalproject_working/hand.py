import itertools
import os
import random
import pygame
from cards import *
from settings import *

class Hand:
    # Initialize the game window, winner, font, and other properties
    def __init__(self):
        self.display_surface = pygame.display.get_surface()
        self.winner = None
        self.font = pygame.font.Font(GAME_FONT, 120)
        self.win = pygame.Surface((100, 100))
        self.original_win = pygame.Surface((100, 100))
        self.rotation_angle = random.uniform(-10, 10)
        self.win = pygame.transform.rotate(self.original_win, self.rotation_angle)

        # Create players, flop, and dealer objects
        self.p1 = Player()
        self.p2 = Player()
        self.flop = Flop()
        self.players_list = [self.p1, self.p2]
        self.dealer = Dealer(self.players_list, self.flop)

    def render_cards(self):
        # Render player and flop cards on the game window
        for player in self.players_list:
            for card in player.cards:
                self.display_surface.blit(card.card_surf, card.start_position)
        for card in self.flop.cards:
            self.display_surface.blit(card.card_surf, card.position)

    def render_winner(self):
        # Render winner info on the game window
        if self.dealer.determined_winner is not None:
            if self.dealer.determined_winner == "Player 1":
                text = "Player 1 Wins!"
                text_color = (115, 235, 0)
            elif self.dealer.determined_winner == "Player 2":
                text = "Player 2 Wins!"
                text_color = (135, 206, 235)
            elif self.dealer.determined_winner == "Tie":
                text = "Split Pot!"
                text_color = (235, 192, 203)

            coordinates = (520, 100)
            text_surface = self.font.render(text, True, text_color)
            text_rect = text_surface.get_rect()
            text_rect.topleft = coordinates
            rotated_surface = pygame.transform.rotate(text_surface, self.rotation_angle)
            rotated_rect = rotated_surface.get_rect(center=text_rect.center)
            self.display_surface.blit(rotated_surface, rotated_rect)

    def update(self):
        # Update the dealer and render the cards and winner information
        self.dealer.update()
        self.render_cards()
        self.render_winner()


class Dealer:
    # Initialize the Dealer instance with player information and flop
    def __init__(self, players, flop):
        self.determined_winner = None
        self.players_list = players
        self.num_players = len(players)
        self.current_player_index = 0
        self.current_flop_index = 0
        self.printed_flop = False
        self.deck = self.generate_deck()  # Initialize the deck here
        random.shuffle(self.deck)
        self.animating_card = None
        self.can_deal = True
        self.can_deal_flop = False
        self.last_dealt_card_time = pygame.time.get_ticks() - 200
        self.last_dealt_flop_time = pygame.time.get_ticks() - 200
        self.dealt_cards = 0
        self.flop = flop

    def generate_deck(self):
        try:
            fresh_deck = []
            for cv in cardvalues:
                for cs in cardsuits:
                    fresh_deck.append(Card(cv, cs))
            random.shuffle(fresh_deck)
            return fresh_deck
        except Exception as e:
            print(f"An error occurred while generating the deck: {e}")
            return []  # Return an empty list or handle it as appropriate for your application.

    # Inside the Dealer class
    # def cooldowns(self):
    #     current_time = pygame.time.get_ticks()

    #     if self.last_dealt_card_time is not None and current_time - self.last_dealt_card_time > 200:
    #         self.can_deal = True
    #         print("can_deal set to True")

    #     if self.last_dealt_flop_time is not None and current_time - self.last_dealt_flop_time > random.randint(120, 200):
    #         self.can_deal_flop = True
    #         print("can_deal_flop set to True")

        # print(f"current_time: {current_time}, last_dealt_card_time: {self.last_dealt_card_time}")

    def cooldowns(self):
        current_time = pygame.time.get_ticks()

        if self.last_dealt_card_time and current_time - 200 > self.last_dealt_card_time:
            self.can_deal = True

        if self.last_dealt_flop_time and current_time - self.last_dealt_flop_time > random.randint(120, 200):
            self.can_deal_flop = True

        # print(f"current_time: {current_time}, last_dealt_card_time: {self.last_dealt_card_time}")
        

    # Inside the Dealer class
    def update(self):
        self.dealt_cards = self.update_dealt_card_count()
        self.cooldowns()

        if self.dealt_cards < (self.num_players * 2):
            # print(f"Dealt cards: {self.dealt_cards}, Player Index: {self.current_player_index}")
            # self.deal_hole_cards(self.animating_card)
            self.deal_hole_cards()

        if self.animating_card:
            self.animate_hole_cards(self.animating_card)

        if self.dealt_cards == (self.num_players * 2) and (not self.animating_card or self.animating_card.animation_complete):
            self.can_deal_flop = True
            self.deal_flop()

        if self.dealt_cards < (self.num_players * 2) + 3 and self.can_deal_flop:
            self.deal_flop()

        if not self.printed_flop and self.dealt_cards == (self.num_players * 2) + 3:
            self.print_hands()
            self.printed_flop = True

        if self.dealt_cards == ((self.num_players * 2) + 3) and self.determined_winner is None:
            eval_cards = [card.id for card in self.players_list[0].cards] + [
                card.id for card in self.flop.cards] + [card.id for card in self.players_list[1].cards]
            self.determined_winner = self.eval_winner(eval_cards)

class Dealer:
    def __init__(self, players, flop):
        # Initialize the Dealer instance with player information and flop
        self.determined_winner = None
        self.players_list = players
        self.num_players = len(players)
        self.current_player_index = 0
        self.current_flop_index = 0
        self.printed_flop = False
        # Initialize the deck and shuffle it
        self.deck = self.generate_deck()
        random.shuffle(self.deck)
        self.animating_card = None
        self.can_deal = True
        self.can_deal_flop = False
        self.last_dealt_card_time = pygame.time.get_ticks() - 200
        self.last_dealt_flop_time = pygame.time.get_ticks() - 200
        self.dealt_cards = 0
        self.flop = flop

    def generate_deck(self):
        try:
            # Generate a deck of cards and shuffle it
            fresh_deck = []
            for cv in cardvalues:
                for cs in cardsuits:
                    fresh_deck.append(Card(cv, cs))
            random.shuffle(fresh_deck)
            return fresh_deck
        except Exception as e:
            print(f"An error occurred while generating the deck: {e}")
            return []

    def cooldowns(self):
        # Update cooldowns for dealing cards and flop
        current_time = pygame.time.get_ticks()

        if self.last_dealt_card_time and current_time - 200 > self.last_dealt_card_time:
            self.can_deal = True

        if self.last_dealt_flop_time and current_time - self.last_dealt_flop_time > random.randint(120, 200):
            self.can_deal_flop = True

    def update(self):
        # Update the game state
        self.dealt_cards = self.update_dealt_card_count()
        self.cooldowns()

        # Deal hole cards to players
        if self.dealt_cards < (self.num_players * 2):
            self.deal_hole_cards()

        # Animate hole cards if needed
        if self.animating_card:
            self.animate_hole_cards(self.animating_card)

        # Deal flop if conditions are met
        if self.dealt_cards == (self.num_players * 2) and (not self.animating_card or self.animating_card.animation_complete):
            self.can_deal_flop = True
            self.deal_flop()

        # Deal flop cards
        if self.dealt_cards < (self.num_players * 2) + 3 and self.can_deal_flop:
            self.deal_flop()

        # Print hands after dealing flop
        if not self.printed_flop and self.dealt_cards == (self.num_players * 2) + 3:
            self.print_hands()
            self.printed_flop = True

        # Evaluate the winner
        if self.dealt_cards == ((self.num_players * 2) + 3) and self.determined_winner is None:
            eval_cards = [card.id for card in self.players_list[0].cards] + [
                card.id for card in self.flop.cards] + [card.id for card in self.players_list[1].cards]
            self.determined_winner = self.eval_winner(eval_cards)

    def update_dealt_card_count(self):
        # Count the total number of dealt cards
        total_card_count = 0
        for player in self.players_list:
            total_card_count += len(player.cards)
        total_card_count += len(self.flop.cards)
        return total_card_count

    def animate_hole_cards(self, card):
        # Animate the dealing of hole cards
        current_time = pygame.time.get_ticks()

        if self.last_dealt_card_time is not None:
            elapsed_time = current_time - self.last_dealt_card_time

            current_card = card
            animation_duration = 200

            if elapsed_time < animation_duration:
                x_orig, y_orig = current_card.orig_position

                # Check if current_card.position is not None before unpacking
                if current_card.position is not None:
                    x_final, y_final = current_card.position
                    elapsed_ratio = elapsed_time / animation_duration
                    x_change = x_orig + (x_final - x_orig) * elapsed_ratio
                    y_change = y_orig + (y_final - y_orig) * elapsed_ratio
                    current_card.start_position = (x_change, y_change)
                else:
                    # Handle the case where current_card.position is None
                    print("Error: current_card.position is None")

            else:
                card.animation_complete = True

    def deal_hole_cards(self):
        # Deal hole cards to players
        if self.can_deal:
            current_player = self.players_list[self.current_player_index]

            # Check if the deck is not empty before popping
            if self.deck:
                current_player.cards.append(self.deck.pop(-1))

                if self.current_player_index == 0:
                    # Set position for player 1 cards
                    if len(current_player.cards) == 1:
                        current_player.cards[0].position = (P1_C1[0], current_player.cards[0].card_y)

                    elif len(current_player.cards) == 2:
                        current_player.cards[1].position = (P1_C2[0], current_player.cards[1].card_y)
                        
                    self.animating_card = current_player.cards[-1]
                elif self.current_player_index == 1:
                    # Set position for player 2 cards
                    if len(current_player.cards) == 1:
                        current_player.cards[0].position = ((P2_C1[0] - current_player.cards[0].card_surf.get_width() - 500), current_player.cards[0].card_y)

                    elif len(current_player.cards) == 2:
                        current_player.cards[1].position = ((P2_C2[0] - current_player.cards[1].card_surf.get_width() - 400), current_player.cards[1].card_y)
                    self.animating_card = current_player.cards[-1]

                # Animate the dealing of cards
                if self.animating_card:
                    self.last_dealt_card_time = pygame.time.get_ticks()
                    self.animate_hole_cards(self.animating_card)

                # Change player index and set dealer cooldown
                self.current_player_index = (self.current_player_index + 1) % self.num_players
                self.can_deal = False

    def eval_hand(self, hand):
        # Evaluate the hand and return ranking and high cards
        values = sorted([c[0] for c in hand], reverse=True)
        suits = [c[1] for c in hand]
        straight = (values == list(range(values[0], values[0] - 5, -1)) or values == [14, 5, 4, 3, 2])
        flush = all(s == suits[0] for s in suits)

        if straight and flush:
            return 8, values[1]
        if flush:
            return 5, values
        if straight:
            return 4, values[1]

        trips = []
        pairs = []
        for v, group in itertools.groupby(values):
            count = sum(1 for _ in group)
            if count == 4:
                return 7, v, values
            elif count == 3:
                trips.append(v)
            elif count == 2:
                pairs.append(v)
        if trips:
            return (6 if pairs else 3), trips, pairs, values
        return len(pairs), pairs, values

    def eval_winner(self, hand_to_eval):
        # Evaluate the winner based on hands
        eval_cards = [(value_dict[x[0]], x[1]) for x in hand_to_eval]
        eval_hand1 = self.eval_hand(eval_cards[:5])
        eval_hand2 = self.eval_hand(eval_cards[5:])

        if eval_hand1 is not None and eval_hand2 is not None:
            if eval_hand1 > eval_hand2:
                print(f"P1 WIN: {eval_hand1}")
                return "Player 1"
            elif eval_hand1 < eval_hand2:
                print(f"P2 WIN: {eval_hand2}")
                return "Player 2"
            else:
                print("SPLIT")
                return "Tie"
        else:
            print("Error: eval_hand returned None for one of the hands.")
            return None

    def print_hands(self):
        # Print the hands of each player and the flop
        for i in range(len(self.players_list)):
            print(f"p{i + 1}: {[card.id for card in self.players_list[i].cards]}")
        print(f"FL: {[card.id for card in self.flop.cards]}")

    def tiebreaker(self, hand1, hand2, hand1_info, hand2_info):
        # Break ties between hands
        assert (type(hand1_info) != list)
        assert (type(hand1_info) == int)
        if hand1_info != hand2_info:
            return (hand1_info > hand2_info)

        values1 = sorted((c[0] for c in hand1), reverse=True)
        values2 = sorted((c[0] for c in hand2), reverse=True)
        return (values1 > values2)

    def deal_flop(self):
        # Deal flop cards
        flop_x = self.players_list[0].cards[0].card_surf.get_width()
        if self.current_flop_index == 0:
            flop_x = self.players_list[0].cards[0].card_surf.get_width() * 3
        elif self.current_flop_index == 1:
            flop_x = self.players_list[0].cards[0].card_surf.get_width() * 3 + (
                        self.players_list[0].cards[0].card_surf.get_width() + 20)
        elif self.current_flop_index == 2:
            flop_x = self.players_list[0].cards[0].card_surf.get_width() * 3 + (
                        self.players_list[0].cards[0].card_surf.get_width() * 2 + 40)

        if self.can_deal and self.can_deal_flop and self.dealt_cards - (self.num_players * 2) < 3:
            self.flop.cards.append(self.deck[-1])
            self.flop.cards[self.current_flop_index].position = (
            flop_x, self.flop.cards[self.current_flop_index].card_y)

            self.deck.pop(-1)
            self.last_dealt_flop_time = pygame.time.get_ticks()
            self.can_deal_flop = False
            self.current_flop_index += 1

        player1_wins = 0
        ranks1 = [0] * 10
        ranks2 = [0] * 10
        try:
            # Evaluate hands and determine the winner
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
                    hand1_rank, hand1_info = self.eval_hand(hand1)
                    hand2_rank, hand2_info = self.eval_hand(hand2)

                    ranks1[hand1_rank] += 1
                    ranks2[hand2_rank] += 1

                    if hand1_rank > hand2_rank:
                        player1_wins += 1

                    elif hand1_rank == hand2_rank and self.tiebreaker(hand1, hand2, hand1_info, hand2_info):
                        player1_wins += 1

        except FileNotFoundError:
            print("Error: File 'p054_poker.txt' not found.")
        except Exception as e:
            print(f"An unexpected error occurred: {e}")

        

class Flop:
    def __init__(self):
        self.cards = []

class Player:
    def __init__(self):
        self.cards = []
