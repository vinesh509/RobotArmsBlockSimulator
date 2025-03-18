#include <iostream>
#include <cstring>
using namespace std;

char St_Ini[2][15], St_Fnl[2][15], arm[2];
int St_Fnl_len[2], state = 0;

void Prnt_St()
{
    
    cout << "State (S" << state++ << ")\n\n";

    for (int i = 0; i < 2; i++)
    {
        cout << "\tR" << i + 1 << ": " << arm[i];
    }
    cout << "\n\n\n";
    cout << "\n";

    int rng1 = strlen(St_Ini[0]);
    int rng2 = strlen(St_Ini[1]);
    int rng_mx = rng1 > rng2 ? rng1 : rng2;

    for (int i = rng_mx - 1; i >= 0; i--)
    {
        cout << "\t";
        if (rng1 > i)
        {
            cout << St_Ini[0][i];
        }
        else
        {
            cout << " ";
        }
        cout << "\t";
        if (rng2 > i)
        {
            cout << St_Ini[1][i];
        }
        else
        {
            cout << " ";
        }
        cout << "\n";
    }
    int i = 0;
    while (i < 35)
    {
        cout << "-";
        i++;
    }
    cout << "\n";

    cout << "\tL1\tL2\n\n";
}

void Actn_Blk(int strt_state, int start_indx_blk, int stop_state, int stop_ind_blk)
{
    int start, end;
    while (true)
    {
        start = strlen(St_Ini[strt_state]);
        end = strlen(St_Ini[!strt_state]);
        if (start - 1 == start_indx_blk)
            break;
        arm[0] = St_Ini[strt_state][start - 1];
        St_Ini[strt_state][start - 1] = 0;
        cout << "Arm: R1 - ";
        if ((start - 1) == 0)
        {
            cout << "Action: Pickup(" << arm[0] << ",L" << strt_state + 1 << ")\n";
        }
        else
        {
            cout << "Action: Unstack(" << arm[0] << ",L" << strt_state + 1 << ")\n";
        }
        Prnt_St();
        cout << "Arm: R1 - Action: Move(" << arm[0] << ",L" << !strt_state + 1 << ")\n";
        Prnt_St();
        St_Ini[!strt_state][end] = arm[0];
        St_Ini[!strt_state][end + 1] = 0;
        if (end == 0)
        {
            cout << "Arm: R1 - Action: PutDown(" << arm[0] << ",L" << !strt_state + 1 << ")\n";
        }
        else
        {
            cout << "Arm: R1 - Action: Stack(" << arm[0] << ",L" << !strt_state + 1 << ")\n";
        }
        arm[0] = ' ';
        Prnt_St();
    }

    arm[0] = St_Ini[strt_state][start - 1];
    St_Ini[strt_state][start - 1] = 0;
    cout << "Arm: R1 - ";
    if ((start - 1) == 0)
    {
        cout << "Action: Pickup(" << arm[0] << ",L" << strt_state + 1 << ")\n";
    }
    else
    {
        cout << "Action: Unstack(" << arm[0] << ",L" << strt_state + 1 << ")\n";
    }
    Prnt_St();

    while (true)
    {
        start = strlen(St_Ini[stop_state]);
        end = strlen(St_Ini[!stop_state]);
        if (start == stop_ind_blk)
            break;

        arm[1] = St_Ini[stop_state][start - 1];
        St_Ini[stop_state][start - 1] = 0;
        cout << "Arm: R2 - ";
        if ((start - 1) == 0)
        {
            cout << "Action: Pickup(" << arm[1] << ",L" << stop_state + 1 << ")\n";
        }
        else
        {
            cout << "Action: Unstack(" << arm[1] << ",L" << stop_state + 1 << ")\n";
        }
        Prnt_St();
        cout << "Arm: R2 - Action: Move(" << arm[1] << ",L" << !stop_state + 1 << ")\n";
        Prnt_St();
        St_Ini[!stop_state][end] = arm[1];
        St_Ini[!stop_state][end + 1] = 0;
        if (end == 0)
        {
            cout << "Arm: R2 - Action: PutDown(" << arm[1] << ",L" << !stop_state + 1 << ")\n";
        }
        else
        {
            cout << "Arm: R2 - Action: Stack(" << arm[1] << ",L" << !stop_state + 1 << ")\n";
        }

        arm[1] = ' ';
        Prnt_St();
    }

    St_Ini[stop_state][start] = arm[0];
    if (start == 0)
    {
        cout << "Arm: R2 - Action: PutDown(" << arm[0] << ",L" << stop_state + 1 << ")\n";
    }
    else
    {
        cout << "Arm: R2 - Action: Stack(" << arm[0] << ",L" << stop_state + 1 << ")\n";
    }

    arm[0] = ' ';
    St_Ini[stop_state][start + 1] = 0;
    Prnt_St();
}

int main() {
    char blk_input;
    int blk_input_loc_len = 0, block_Id;

    cout << "Enter Initial State" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Enter the number of blocks in L" << i + 1 << ":  ";
        cin >> blk_input_loc_len;
        puts("");
        cout << "Enter block names from bottom: " << endl;
        for (block_Id = 0; block_Id < blk_input_loc_len; block_Id++) {
            cout << "Enter " << block_Id + 1 << "th block: ";
            cin >> blk_input;
            St_Ini[i][block_Id] = blk_input;
        }
        St_Ini[i][block_Id] = 0;
        puts("");
    }

    puts("");
    cout << "Enter Final State" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Enter the number of blocks in L" << i + 1 << ":  ";
        cin >> blk_input_loc_len;
        St_Fnl_len[i] = blk_input_loc_len;
        puts("");
        cout << "Enter block names from bottom: " << endl;
        for (block_Id = 0; block_Id < blk_input_loc_len; block_Id++) {
            cout << "Enter " << block_Id + 1 << "th block: ";
            cin >> blk_input;
            St_Fnl[i][block_Id] = blk_input;
        }
        St_Fnl[i][block_Id] = 0;
        puts("");
    }

    Prnt_St();

    for (int i = 0; i < 2; i++) {
        for (int len = 0; len < St_Fnl_len[i]; len++) {
            char blockChar = St_Fnl[i][len];
            int block_position = 0, block_state_id = 0;

            arm[0] = ' ';
            arm[1] = ' ';

            for (block_position = 0; block_position < 2; block_position++) {
                block_state_id = strchr(St_Ini[block_position], blockChar) - St_Ini[block_position];
                if (block_state_id >= 0 && block_state_id < strlen(St_Ini[block_position])) {
                    break;
                }
            }

            if (block_position < 2 && !(block_position == i && block_state_id == len)) {
                Actn_Blk(block_position, block_state_id, i, len);
            }
        }
    }

    return 0;
}

