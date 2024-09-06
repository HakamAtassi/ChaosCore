

        #val flush                           =   Input(Bool())

        #// CHECKPOINT 
        #val commit                          =   Flipped(ValidIO(new commit(coreParameters)))
        #val partial_commit          =      Input(new partial_commit(coreParameters))                                         // commit mem op

        #// Instruction input (decoded)
        #val decoded_fetch_packet            =   Flipped(Decoupled(new decoded_fetch_packet(coreParameters)))

        #val FU_outputs                      =   Vec(portCount, Flipped(ValidIO(new FU_output(coreParameters))))

        #// Instruction output (renamed)
        #val renamed_decoded_fetch_packet    =   Decoupled(new decoded_fetch_packet(coreParameters))


# An RD cannot be ready unless its been committed. RDs start off ready
# An RS1/RS2 cannot be ready if it has not been marked as such by an FU. they also start off ready

# back pressure









class rename_TB:
    def __init__(self):
        pass


